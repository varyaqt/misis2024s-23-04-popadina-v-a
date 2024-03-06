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


	std::cout << "CONJUGATE TO THE" << c1 << ": " << conjugate(c1) << std::endl;
	std::cout << "CONJUGATE TO THE" << c2 << ": " << conjugate(c2) << std::endl;

	std::cout << c1 << " == " << c2 << ": " static_cast<bool>(c1 == c2) << std::endl;
	std::cout << c1 << " != " << c2 << ": " static_cast<bool>(c1 != c2) << std::endl;

int main() {
	test();
	return 0;
}
