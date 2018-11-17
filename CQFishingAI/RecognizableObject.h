#pragma once
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>

using namespace cv;
using namespace std;

class RecognizableObject
{
public:
	RecognizableObject();
	~RecognizableObject();


	virtual Mat FilterMask(Mat);								// 輸入：原圖、輸出：CV_8U 的 Mask (白代表有東西)
};

