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
	namedWindow("原始影像");
	moveWindow("原始影像", -1920, 0);
	#endif
	#pragma endregion
}
CQFishingAI::~CQFishingAI()
{
	delete timer;
}

void CQFishingAI::CaptureScreen()
{
	/*	while (true)
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
	destroyWindow("原始");*/
	#pragma region 抓取畫面資料
	// 這邊主要分兩個部分
	// 1. 使用 WinAPI 抓取畫面位置
	// 2. 使用 Video
	Mat screen;
	#ifndef TEST_ON_VIDEO
	#else
	capVideo >> screen;
	
	// 如果是空的話
	// 停止
	if (screen.empty() || times > 4000)
	{
		timer->stop();
		destroyWindow("原始影像");
		return;
	}

	// 擷取有用的地方
	screen = screen(Rect(
		UsefulStartPosition.x(), UsefulStartPosition.y(),			// x, y
		UsefulEndPosition.x() - UsefulStartPosition.x(),			// Width
		UsefulEndPosition.y() - UsefulStartPosition.y()				// Height
	));
	QString FileLocation = "D:/5-1/" + QString::number(times++) + ".png";
	imwrite(FileLocation.toStdString(), screen);
	#endif // !TEST_ON_VIDEO
	#pragma endregion
	#pragma region 顯示 Debug 結果
	#ifdef DEBUG_RESULT
	cv::resize(screen.clone(), screen, Size(screen.cols / ResultDebugSizeScale, screen.rows / ResultDebugSizeScale));
	imshow("原始影像", screen);
	#endif
	#pragma endregion
}
