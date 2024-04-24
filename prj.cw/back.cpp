#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include <iostream>
#include <cmath>

int main() {
    cv::Mat img;
    img = cv::imread("C:/Users/popad/Desktop/tests/panda.jpg", cv::IMREAD_COLOR);
    if (!img.data) {
        std::cerr << "Error: the image wasn't correctly loaded." << std::endl;
        return -1;
    }
    int64_t userSize = 0;
    std::cout << "What is the size of the longest side?\n";
    std::cin >> userSize;
    while (userSize <= 0) {
        std::cout << "The impossible size of the circuit.the size must be positive.\n";
        std::cout << "What is the size of the longest side?\n";
        std::cin >> userSize;
    }
    cv::Mat mosaic = img.clone();
    int a = img.rows;
    int b = img.cols;
    int p = 0;
    if (a > b) {
        if (a % userSize == 0) p = a / userSize;
        else p = static_cast<int>(a / userSize) + 1;
    }
    else {
        if (b % userSize == 0) p = b / userSize;
        else p = static_cast<int>(b / userSize) + 1;
    }
    if (img.rows % p != 0) {
        a = (std::trunc(img.rows / p) + 1) * p;
    }
    if (img.cols % p != 0) {
        b = (std::trunc(img.cols / p) + 1) * p;
    }
    cv::Mat img2;
    cv::resize(img, img2, cv::Size(a, b));
    for (int y = 0; y < img2.rows; y += p) {
        for (int x = 0; x < img2.cols; x += p) {
            cv::Rect region(x, y, p, p);
            int Pixels = p * p;
            int B = 0, G = 0, R = 0;
            for (int j = y; j < y + p; j++) {
                for (int i = x; i < x + p; i++) {
                    cv::Vec3b pixel = img2.at<cv::Vec3b>(j, i);
                    B += pixel[0];
                    G += pixel[1];
                    R += pixel[2];
                }
            }
            cv::Scalar meanColor = cv::Scalar(B / Pixels, G / Pixels, R / Pixels);
            cv::rectangle(mosaic, region, meanColor, cv::FILLED);
        }
    }
    cv::imshow("output.jpg", mosaic);
    cv::imwrite("C:/Users/popad/Desktop/tests/result.jpg", mosaic);
    cv::waitKey();
    return 0;
}
