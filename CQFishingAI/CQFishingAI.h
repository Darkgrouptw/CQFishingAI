#pragma once
#include <iostream>
#include <QDir>

#include <QtWidgets/QMainWindow>
#include "ui_CQFishingAI.h"

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class CQFishingAI : public QMainWindow
{
	Q_OBJECT

public:
	CQFishingAI(QWidget *parent = Q_NULLPTR);

private:
	Ui::CQFishingAIClass ui;
};
