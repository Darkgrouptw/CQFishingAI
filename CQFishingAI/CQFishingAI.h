#pragma once
#include <iostream>
#include <QDir>

#include <QtWidgets/QMainWindow>
#include "ui_CQFishingAI.h"
#include "GlobalDefine.h"

#include <QTimer>
#include <QSize>
#include <QVector2D>

#include <opencv2/opencv.hpp>
//#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

class CQFishingAI : public QMainWindow
{
	Q_OBJECT

public:
	CQFishingAI(QWidget *parent = Q_NULLPTR);
	~CQFishingAI();

private:
	Ui::CQFishingAIClass ui;

	//////////////////////////////////////////////////////////////////////////
	// 系統相關參數 (後面要搬到 CaptureScreen 的 Function 裡)
	//////////////////////////////////////////////////////////////////////////
	const QSize		ScreenSize				= QSize(1416, 884);
	const QVector2D	UsefulStartPosition		= QVector2D(7, 48);
	const QVector2D	UsefulEndPosition		= QVector2D(1414, 838);


	//////////////////////////////////////////////////////////////////////////
	// 計時相關的
	//////////////////////////////////////////////////////////////////////////
	QTimer			*timer;
	const int		FPS = 60;
	float			millisec = 1000.0 / FPS;
	int				times = 0;

	//////////////////////////////////////////////////////////////////////////
	// 測試使用
	// TEST_ON_VIDEO & DEBUG_RESULT
	//////////////////////////////////////////////////////////////////////////
	VideoCapture	capVideo;
	QString			videoLocation = "C:/Users/Dark/Documents/Bandicam/5-1.mp4";
	// QString			videoLocation = "C:/Users/Dark/Documents/Bandicam/6-1.mp4";
	float			ResultDebugSizeScale = 1.f;


private slots:
	void			CaptureScreen();											// 要去拿畫面資料了						
};
