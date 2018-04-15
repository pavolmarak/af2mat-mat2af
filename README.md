# AF2MAT and MAT2AF
**Conversion functions** to help pass data between ArrayFire's `af::array` object and OpenCV's `cv::Mat`. In this Qt project we demonstrate possibility to pass **grayscale** (fingerprint) image data from `af::array` to `cv::Mat` and vice-versa. It is very common to use both ArrayFire and OpenCV library in image processing applications and therefore we find it helpful to provide these convenience conversion functions.

Please keep in mind that this conversion utility **works only for grayscale images**.

![alt text](img/app_1_0_0.png "Application's user interface")

This project **depends** on these 3rd-party libraries:
* [ArrayFire 3.5.1](https://github.com/arrayfire/arrayfire) (tested)
* [OpenCV 3.4.1](https://opencv.org/releases.html) (tested)

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

Here are some examples of using `Converter` class:

**Conversion from `af::array` to `cv::Mat`** 

```cpp
af::array input = af::loadImage(filename);
// converting af::array to cv::Mat
cv::Mat output = Converter::af2mat(input);
// displaying cv::Mat
cv::imshow("Output in OPENCV",output);
```

**Conversion from `cv::Mat` to `af::array`** 

```cpp
// loading grayscale image
cv::Mat input = cv::imread(filename,cv::IMREAD_GRAYSCALE);
// converting cv::Mat to af::array
af::array output = Converter::mat2af(input);
// displaying af::array
af::Window window(output.dims(1), output.dims(0), "Output in ARRAYFIRE");
do
  {
    window.image(output);
  } 
while(!window.close());
```

