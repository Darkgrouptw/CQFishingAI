#include "Wheel.h"

Wheel::Wheel()
{
	#pragma region 設定 Working Area
	WorkingArea = Rect(1176, 561, 230, 230);
	#pragma endregion
}
Wheel::~Wheel()
{
}

//////////////////////////////////////////////////////////////////////////
// 抓取有效的區塊
//////////////////////////////////////////////////////////////////////////
bool Wheel::FilterMask(Mat img, Mat& mask)
{
	// 宣告
	mask = Mat::zeros(WorkingArea.height, WorkingArea.width, CV_8U);
	Mat checkArea = img(WorkingArea);

	// 轉灰階取二值化
	cvtColor(checkArea, checkArea, CV_BGR2GRAY);
	threshold(checkArea, checkArea, 10, 255, THRESH_BINARY_INV);

	// 先確定是否是有用的值
	float usefulArea = (float)countNonZero(checkArea) / WorkingArea.width / WorkingArea.height;
	if (usefulArea > ValidThreshold)
	{
		assert(false);
		return false;
	}

	// Find Contours
	vector<vector<Point>> contours;
	Mat tempMat = Mat::zeros(WorkingArea.height, WorkingArea.width, CV_8U);;
	findContours(checkArea, contours, RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, Point());
	drawContours(tempMat, contours, -1, Scalar(255), FILLED);

	// 因為會切斷，所以擴張
	dilate(tempMat, tempMat, Mat(), Point(-1, -1), 5);

	// 再找一次
	findContours(tempMat, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, Point());

	// 先判斷是否抓不到邊界
	if (contours.size() == 0)
		return false;

	// 只拿出最大塊的 Contour
	float maxArea = contourArea(contours[0]);
	int maxIndex = 0;
	for (int i = 1; i < contours.size(); i++)
	{
		float tempArea = contourArea(contours[i]);
		if (maxArea < tempArea)
		{
			maxArea = tempArea;
			maxIndex = i;
		}
	}
	
	// 在最一次判斷
	if (maxArea < FinalAreaThreshold)
		assert(false);

	// 只留最大的
	vector<vector<Point>> filterContours;
	filterContours.push_back(contours[maxIndex]);

	fillPoly(mask, filterContours, Scalar(255));
	erode(mask, mask, Mat(), Point(-1, -1), 5);
	return true;
}
