# AF2MAT-MAT2AF
Conversion functions to help pass data between ArrayFire's `af::array` object and OpenCV's `cv::Mat`. In this Qt project we demonstrate possibility to pass grayscale (fingerprint) image data from `af::array` to `cv::Mat` and vice-versa. It is very common to use both ArrayFire and OpenCV library in image processing applications and therefore we find it helpful to provide these convenience conversion functions.

This project **depends** on these 3rd-party libraries:
* ArrayFire 3.5.1 (tested)
* OpenCV 3.4.1 (tested)

This project contains a class called `Converter` that has 2 static member functions to perform conversion as follows:

```cpp
cv::Mat af2mat(const af::array& input);
```
This function takes `af::array` constant reference as input and returns a new `cv::Mat` containing a deep copy of input data. 

```cpp
af::array mat2af(const cv::Mat& input);
```
This function takes `cv::Mat` constant reference as input and returns a new `af::array` containing a deep copy of input data. 

Both functions do not allocate any extra dynamic memory, so users do not need to free anything just use the returned data until it is alive within its scope. 


