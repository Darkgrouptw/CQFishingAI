#include "RecognizableObject.h"

RecognizableObject::RecognizableObject()
{
}
RecognizableObject::~RecognizableObject()
{
}

Mat RecognizableObject::FilterMask(Mat img)
{
	Mat mask = Mat::zeros(img.size(), CV_8U);
	return  mask;
}
