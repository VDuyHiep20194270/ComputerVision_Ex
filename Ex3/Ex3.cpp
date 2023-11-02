#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;

int main() {
    Mat image1 = imread("Picture1.png", 0);
    Mat image2 = imread("Picture2.png", 0);
    printf("%d %d %d %d",image1.cols,image1.rows, image2.cols, image2.rows);
    resize(image2, image2, Size(206, 167));
    Mat result;
    bitwise_and(image1, image2, result);  // AND logic giữa image1 và image2
    imshow("Image 1", image1);
    imshow("Image 2", image2);
    imshow("AND Image", result);
    waitKey(0);
    return 0;
}