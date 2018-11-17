#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CQFishingAI.h"

class CQFishingAI : public QMainWindow
{
	Q_OBJECT

public:
	CQFishingAI(QWidget *parent = Q_NULLPTR);

private:
	Ui::CQFishingAIClass ui;
};
