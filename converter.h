#ifndef CONVERTER_H
#define CONVERTER_H

#include "opencv2/opencv.hpp"
#include "arrayfire.h"

class Converter
{
public:
    Converter();
    static cv::Mat af2mat(const af::array& input);
    static af::array mat2af(const cv::Mat& input);
};

#endif // CONVERTER_H
