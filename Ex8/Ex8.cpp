#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main() {
    // Đọc ảnh bàn cờ vua
    cv::Mat image = cv::imread("thumbnail.jpg");

    if (image.empty()) {
        std::cout << "Không thể đọc ảnh." << std::endl;
        return -1;
    }

    // Chuyển ảnh sang ảnh đen trắng
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // Sử dụng phép biến đổi Canny để phát hiện cạnh
    cv::Mat edges;
    cv::Canny(gray, edges, 50, 150, 3);

    // Sử dụng RANSAC để tìm các đường thẳng
    std::vector<cv::Vec4i> lines;
    cv::Ptr<cv::LineSegmentDetector> ls = cv::createLineSegmentDetector();
    ls->detect(edges, lines);

    // Vẽ các đường thẳng lên ảnh gốc
    for (size_t i = 0; i < lines.size(); i++) {
        cv::line(image, cv::Point(lines[i][0], lines[i][1]), cv::Point(lines[i][2], lines[i][3]), cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
    }

    // Hiển thị ảnh với các đường thẳng đã vẽ
    cv::imshow("RANSAC Lines", image);
    cv::imwrite("Detection.jpg",image);
    cv::waitKey(0);

    return 0;
}
