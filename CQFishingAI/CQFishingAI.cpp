#include "CQFishingAI.h"

CQFishingAI::CQFishingAI(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	VideoCapture cap("./TestVideos/5-1.mp4");
	if (!cap.isOpened())
	{
		cout << "讀不到影片" << endl;
		cout << QDir().absolutePath().toStdString() << endl;
	}
	namedWindow("原始");
	moveWindow("原始", -1920, 0);
	while (true)
	{
		Mat frame;
		cap >> frame;

		if (frame.empty())
			break;

		imshow("原始", frame);

		// ESC
		char c = (char)waitKey(25);
		if (c == 27)
			break;
	}
	destroyWindow("原始");
}
