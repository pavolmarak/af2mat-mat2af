#ifndef CONVERTER_H
#define CONVERTER_H

#include "opencv2/opencv.hpp"
#include "arrayfire.h"

// cv::Mat types

//  +--------+----+----+----+----+------+------+------+------+
//  |        | C1 | C2 | C3 | C4 | C(5) | C(6) | C(7) | C(8) |
//  +--------+----+----+----+----+------+------+------+------+
//  | CV_8U  |  0 |  8 | 16 | 24 |   32 |   40 |   48 |   56 |
//  | CV_8S  |  1 |  9 | 17 | 25 |   33 |   41 |   49 |   57 |
//  | CV_16U |  2 | 10 | 18 | 26 |   34 |   42 |   50 |   58 |
//  | CV_16S |  3 | 11 | 19 | 27 |   35 |   43 |   51 |   59 |
//  | CV_32S |  4 | 12 | 20 | 28 |   36 |   44 |   52 |   60 |
//  | CV_32F |  5 | 13 | 21 | 29 |   37 |   45 |   53 |   61 |
//  | CV_64F |  6 | 14 | 22 | 30 |   38 |   46 |   54 |   62 |
//  +--------+----+----+----+----+------+------+------+------+

// af::array types

//    f32   32-bit floating point values
//    c32 	32-bit complex floating point values
//    f64 	64-bit complex floating point values
//    c64 	64-bit complex floating point values
//    b8    8-bit boolean values
//    s32 	32-bit signed integral values
//    u32 	32-bit unsigned integral values
//    u8    8-bit unsigned integral values
//    s64 	64-bit signed integral values
//    u64 	64-bit unsigned integral values
//    s16 	16-bit signed integral values
//    u16 	16-bit unsigned integral values

class Converter
{
public:
    Converter();
    static cv::Mat af2mat(const af::array& input);
    static af::array mat2af(const cv::Mat& input);
};

#endif // CONVERTER_H
