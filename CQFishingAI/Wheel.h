﻿#pragma once
#include "RecognizableObject.h"

class Wheel : public RecognizableObject
{
public:
	Wheel();
	~Wheel();

	//////////////////////////////////////////////////////////////////////////
	// 抓取有效的區塊
	//////////////////////////////////////////////////////////////////////////
	bool				FilterMask(Mat, Mat&);

private:
	//////////////////////////////////////////////////////////////////////////
	// 設定
	//////////////////////////////////////////////////////////////////////////
	Rect			WorkingArea;
	const float		ValidThreshold = 0.05f;											// 在一開始抓出邊界的時候，有效的點數沒有超過這個 Threshold
	const float		FinalAreaThreshold = 0.54f;										// 最後找的整塊區域，判斷是否有大於這個結果
	const int		BinaryThreshold = 10;											// 二值化
};

