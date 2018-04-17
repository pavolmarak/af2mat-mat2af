#include "converter.h"

#include <QDebug>

Converter::Converter()
{

}

cv::Mat Converter::af2mat(const af::array &input)
{
    uchar* data = input.as(u8).T().host<uchar>();
    cv::Mat output = cv::Mat((int)input.dims(0), (int)input.dims(1), CV_8UC1, data).clone();
    af::freeHost(data);
    return output;
}

af::array Converter::mat2af(const cv::Mat &input)
{
    cv::Mat helperMat;
    cv::transpose(input,helperMat);
    return af::array(input.rows, input.cols, helperMat.data);
}
