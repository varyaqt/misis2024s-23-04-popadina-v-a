#include <complex/complex.hpp>

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
	Complex c1memory = c1;
	Complex checker(0, 0);

	std::cout << "CONJUGATE TO THE FIRST NUMBER: " << conjugate(c1) << std::endl;
	std::cout << "CONJUGATE TO THE SECOND NUMBER: " << conjugate(c2) << std::endl;

	std::cout << "test1.1: addition" << std::endl << "operator+: " << c1 + c2 << std::endl;
	checker = c1 + c2;
	c1 += c2;
	std::cout << "operator+=: " << c1 << std::endl;
	std::cout << std::endl;
	c1 = c1memory;
	std::cout << "test1.2: addition with real" << std::endl << "operator+: " << c1 + real << std::endl;
	checker = c1 + real;
	c1 += real;
	std::cout << "operator+=: " << c1 << std::endl;
	std::cout << std::endl;
	c1 = c1memory;

	std::cout << "test2.1: subtraction" << std::endl << "operator-: " << c1 - c2 << std::endl;
	checker = c1 - c2;
	c1 -= c2;
	std::cout << "operator-=: " << c1 << std::endl;
	std::cout << std::endl;
	c1 = c1memory;
	std::cout << "test2.2: subtraction with real" << std::endl << "operator-: " << c1 - real << std::endl;
	checker = c1 - real;
	c1 -= real;
	std::cout << "operator-=: " << c1 << std::endl;
	std::cout << std::endl;
	c1 = c1memory;

	std::cout << "test3.1: multiplication" << std::endl << "operator*: " << c1 * c2 << std::endl;
	checker = c1 * c2;
	c1 *= c2;
	std::cout << "operator*=: " << c1 << std::endl;
	std::cout << std::endl;
	c1 = c1memory;
	std::cout << "test3.2: multiplication with real" << std::endl << "operator*: " << c1 * real << std::endl;
	checker = c1 * real;
	c1 *= real;
	std::cout << "operator*=: " << c1 << std::endl;
	std::cout << std::endl;
	c1 = c1memory;

	std::cout << "test4: division" << std::endl;
	if (c2 == Complex(0)) std::cout << "BAD! DIVISION BY ZERO";
	else {
		std::cout << "operator/: " << c1 / c2 << std::endl;
		checker = c1 / c2;
		c1 /= c2;
		std::cout << "operator/=: " << c1 << std::endl;
		std::cout << std::endl;
		c1 = c1memory;
	}
	std::cout << "THE MODULE OF THE FIRST NUMBER: " << absolute(c1) << std::endl;
	std::cout << "THE MODULE OF THE SECOND NUMBER: " << absolute(c2) << std::endl;
	std::cout << "ENTER THE DEGREE: ";
	int degree;
	std::cin >> degree;
	std::cout << "RESULT: " << pow(c1, degree) << std::endl;
	std::cout << "FIRST NUM == SECOND NUM: " << static_cast<bool>(c1 == c2) << std::endl;
	std::cout << "FIRST NUM != SECOND NUM: " << static_cast<bool>(c1 != c2) << std::endl;
}

int main() {
	test();
	return 0;
}
