#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include <iostream>
#include <cmath>

int main() {
    cv::Mat img;
    img = cv::imread("C:/Users/popad/Desktop/tests/darsie.jpg", cv::IMREAD_COLOR);
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
    // Получение размеров изображения
    int width = img.cols;
    int height = img.rows;
    // Вычислить размер квадрата
    int square_size = std::min(width / userSize, height / userSize);

    // Вычислить количество квадратов по ширине и высоте
    int userSize_width = std::ceil(static_cast<double>(width) / square_size);
    int userSize_height = std::ceil(static_cast<double>(height) / square_size);

    // Создать пустое мозаичное изображение
    cv::Mat mosaic(userSize_height * square_size, userSize_width * square_size, CV_8UC3, cv::Scalar(0, 0, 0));

    // Итерировать по квадратам
    for (int i = 0; i < height; i += square_size) {
        for (int j = 0; j < width; j += square_size) {
            // Выделить квадрат
            cv::Mat square = img(cv::Rect(j, i, std::min(square_size, width - j), std::min(square_size, height - i)));

            // Вычислить средний цвет квадрата
            cv::Scalar avg_color = mean(square);

            // Заполнить квадрат в мозаичном изображении средним цветом
            rectangle(mosaic, cv::Rect(j / square_size * square_size, i / square_size * square_size, square.cols, square.rows), avg_color, -1);
        }
    }
    imshow("Мозаичное изображение", mosaic);
    imwrite("C:/Users/popad/Desktop/tests/result.jpg", mosaic);
    cv::waitKey(0);
    return 0;

    /*std::cout << "What is the number of colors in the palette?\n";
    int nColors = 0;
    std::cin >> nColors;
    while (nColors <= 0) {
        std::cout << "The impossible number of colors. The number must be positive.\n";
        std::cout << "What is the number of colors in the palette?\n";
        std::cin >> nColors;
    }*/
}
