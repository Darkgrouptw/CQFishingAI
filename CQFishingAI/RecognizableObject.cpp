#include "RecognizableObject.h"

RecognizableObject::RecognizableObject()
{
}
RecognizableObject::~RecognizableObject()
{
}

bool RecognizableObject::FilterMask(Mat img, Mat& mask)
{
	mask = Mat::zeros(img.size(), CV_8U);
	return false;
}
