#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "colors.hpp"
/*C:/Users/popad/Desktop/tests/darsie.jpg*/
int main() {
    cv::Mat img;
    std::cout << "Write the path to the image.\n";
    std::string path;
    std::cin >> path;
    img = cv::imread(path, cv::IMREAD_COLOR);
    if (!img.data) {
        std::cerr << "Error: the img wasn't correctly loaded." << std::endl;
        return -1;
    }
    int userSize = 0;
    std::cout << "What is the size of the longest side?\n";
    std::cin >> userSize;
    while (userSize <= 0) {
        std::cout << "The impossible size of the circuit. The size must be positive.\n";
        std::cout << "What is the size of the longest side?\n";
        std::cin >> userSize;
    }
    int width = img.cols;
    int height = img.rows;
    int square_size = std::min(width / userSize, height / userSize);
    int userSize_width = std::ceil(static_cast<double>(width) / square_size);
    int userSize_height = std::ceil(static_cast<double>(height) / square_size);
    cv::Mat mosaic(userSize_height * square_size, userSize_width * square_size, CV_8UC3, cv::Scalar(0, 0, 0));
    for (int i = 0; i < height; i += square_size) {
        for (int j = 0; j < width; j += square_size) {
            cv::Mat square = img(cv::Rect(j, i, std::min(square_size, width - j), std::min(square_size, height - i)));
            cv::Scalar avg_color = mean(square);
            rectangle(mosaic, cv::Rect(j / square_size * square_size, i / square_size * square_size, square.cols, square.rows), avg_color, -1);
        }
    }
    std::vector<std::string> colors;
    for (int i = 0; i < height; i += square_size) {
        for (int j = 0; j < width; j += square_size) {
            cv::Vec3b pixel_color = img.at<cv::Vec3b>(j, i);
            cv::Vec3b rgb_color;
            rgb_color[0] = pixel_color[2];
            rgb_color[1] = pixel_color[1];
            rgb_color[2] = pixel_color[0];

            auto color_it = color_map.find(rgb_color);
            if (color_it != color_map.end()) {
                std::string thread_number = color_it->second;
                colors.push_back(thread_number);
            }
        }
    }
    std::cout << "We recommend that you try using these thread colors:\n";
    for (auto c : colors) std::cout << c << "\n";
    imshow("Мозаичное изображение", mosaic);
    imwrite("C:/Users/popad/Desktop/tests/result.jpg", mosaic);
    cv::waitKey(0);
    return 0;
} 
