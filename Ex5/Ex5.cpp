#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;

int main() {
    Mat src1 = imread("image1.png", 0);
    Mat src2 = imread("image2.png", 0);
    Mat result;
    subtract(src2, src1, result);

    imshow("Image 1", src1);
    imshow("Image 2", src2);
    imshow("Subtraction Result", result);
    for (int y = 0; y < src1.rows; y++) {
        for (int x = 0; x < src1.cols; x++) {
            result.at<uchar>(y, x) = (result.at<uchar>(y, x)  > 0) ? result.at<uchar>(y, x)  : 0;
        }
    }    
    imwrite("detection.png", result);
    waitKey(0);
    destroyAllWindows();

    return 0;

}