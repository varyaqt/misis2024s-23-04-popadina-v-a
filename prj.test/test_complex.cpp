#include "complex/complex.hpp"

void test() {
	Complex c1(0, 0);
	Complex c2(0, 0);
	double real = 0;
	std::cout << "Input a real-type number: ";
	std::cin >> real;
	std::cout << "Input complex num 1: ";
	std::cin >> c1;
	std::cout << "Input complex num 2: ";
	std::cin >> c2;
	std::cout << "test 1.1: addition" << std::endl;
	std::cout << c1 << "+" << c2 << "=" << c1 + c2 << std::endl;
	std::cout << c1 << "+" << real << "=" << c1 + real << std::endl;
	std::cout << real << "+" << c2 << "=" << real + c2 << std::endl;

	std::cout << "test 1.2: substraction" << std::endl;
	std::cout << c1 << "-" << c2 << "=" << c1 - c2 << std::endl;
	std::cout << c1 << "-" << real << "=" << c1 - real << std::endl;
	std::cout << real << "-" << c2 << "=" << real - c2 << std::endl;

	std::cout << "test 1.3: multiplication" << std::endl;
	std::cout << c1 << "*" << c2 << "=" << c1 * c2 << std::endl;
	std::cout << c1 << "*" << real << "=" << c1 * real << std::endl;
	std::cout << real << "*" << c2 << "=" << real * c2 << std::endl;

	std::cout << "test 1.4: division" << std::endl;

	if (real == 0) {
		throw std::logic_error("it cannot be divided into real");
	}
	else {
		std::cout << c1 << "/" << real << "=" << c1 / real << std::endl;
		std::cout << c2 << "/" << real << "=" << c2 / real << std::endl;
	}
	if (c1 == 0) {
		throw std::logic_error("It is impossible to divide by zero, c1-test broken");
	}
	else {
		std::cout << real << "/" << c1 << "=" << real / c1 << std::endl;
		std::cout << c2 << "/" << c1 << "=" << c2 / c1 << std::endl;
	}

	if (c2 == 0) {
		throw std::logic_error("It is impossible to divide by zero, c2-test broken");
	}
	else {
		std::cout << real << "/" << c2 << "=" << real / c2 << std::endl;
		std::cout << c1 << "/" << c2 << "=" << c1 / c2 << std::endl;
	}

	std::cout << "test 1.5: equality" << std::endl;

	std::cout << c1 << " == " << c2 << ": " << (c1 == c2) << std::endl;
	std::cout << c1 << " != " << c2 << ": " << (c1 != c2) << std::endl;
}
int main() {
	test();
	return 0;
}
