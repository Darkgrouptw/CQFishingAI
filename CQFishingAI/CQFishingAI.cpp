#include "CQFishingAI.h"

CQFishingAI::CQFishingAI(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	#pragma region 創建資料
	// 計時器
	timer = new QTimer();
	timer->start(millisec);

	// 如果是 Video Test 的話
	// 要去讀檔案路徑
	#ifdef TEST_ON_VIDEO
	capVideo.open(videoLocation.toStdString());

	// 要確保有讀到影片
	assert(capVideo.isOpened());
	#endif // DEBUG
	#pragma endregion
	#pragma region Connect 事件
	connect(timer,							SIGNAL(timeout()),			this,		SLOT(CaptureScreen()));
	#pragma endregion
	#pragma region Debug 相關
	#ifdef DEBUG_RESULT
	namedWindow(OrgWindowTitle.toStdString());
	moveWindow(OrgWindowTitle.toStdString(), -1900, 50);
	namedWindow(FeatureWindowTitle.toStdString());
	moveWindow(FeatureWindowTitle.toStdString(), -950, 50);
	#endif
	#pragma endregion
	#pragma region Recognize 部分
	// 轉輪
	Wheel* wheel = new Wheel();
	RecognizeArray.push_back(wheel);
	#pragma endregion
}
CQFishingAI::~CQFishingAI()
{
	#pragma region 刪除其他東西
	delete timer;
	#pragma endregion
	#pragma region Recognize 部分
	for (int i = 0; i < RecognizeArray.size(); i++)
		delete RecognizeArray[i];
	#pragma endregion
}

//////////////////////////////////////////////////////////////////////////
// Helper Function
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Slots
//////////////////////////////////////////////////////////////////////////
void CQFishingAI::CaptureScreen()
{
	#pragma region 抓取畫面資料
	// 這邊主要分兩個部分
	// 1. 使用 WinAPI 抓取畫面位置
	// 2. 使用 Video
	Mat Screen;
	#ifndef TEST_ON_VIDEO
	#else
	// 抓取影像
	capVideo >> Screen;

	// 擷取有用的地方
	Screen = Screen(Rect(
		UsefulStartPosition.x(), UsefulStartPosition.y(),			// x, y
		UsefulEndPosition.x() - UsefulStartPosition.x(),			// Width
		UsefulEndPosition.y() - UsefulStartPosition.y()				// Height
	));

	// Feature 抓取
	/*for (int i = 0; i < RecognizeArray.size(); i++)
	{
		Mat mask = RecognizeArray[i]->FilterMask(Screen);
	}*/
	#endif
	#pragma endregion
	#pragma region 顯示 Debug 結果
	#ifdef DEBUG_RESULT
	// 原始影像
	Mat ScreenResize;
	cv::resize(Screen, ScreenResize, Size(Screen.cols / ResultDebugSizeScale, Screen.rows / ResultDebugSizeScale));
	imshow(OrgWindowTitle.toStdString(), ScreenResize);

	// Debug 後的影像
	Mat featureMask;
	RecognizeArray[0]->FilterMask(Screen, featureMask);
	imshow(FeatureWindowTitle.toStdString(), featureMask);
	#endif
	#pragma endregion
}