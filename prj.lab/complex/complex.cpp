#include "complex/complex.hpp"

bool Complex::operator==(const Complex& rhs) const noexcept {
    constexpr double eps = 2 * std::numeric_limits<double>::epsilon();
    return (std::abs(re - rhs.re) <= eps) && (std::abs(im - rhs.im) <= eps);
}


Complex Complex::operator-() const noexcept {
    return Complex(-re, -im);
}


double abs(const Complex& rhs) noexcept
{
    double ans = std::pow((std::pow(rhs.re, 2) + std::pow(rhs.im, 2)), 0.5);
    return ans;
}

Complex pow(const Complex& lhs, int n)
{
    const Complex c0 = { 0,0 };
    if (lhs == c0 && n == 0) {
        throw std::invalid_argument("Zero to the zero degree!\n");
    }
    if (lhs == c0 && n != 0) {
        return { 0,0 };
    }
    else if (n == 0) {
        return Complex(1);
    }
    else if (n > 0) {
        return lhs * pow(lhs, --n);
    }
    else {
        Complex olhs = (1.0 / lhs);
        return olhs * pow(lhs, ++n);
    }
}

bool operator==(const Complex& lhs, const double rhs) noexcept { return lhs.operator==(Complex(rhs)); }
bool operator==(const double lhs, const Complex& rhs) noexcept { return rhs.operator==(Complex(lhs)); }
bool operator!=(const Complex& lhs, const Complex& rhs) noexcept { return !(lhs.operator==(rhs)); }
bool operator!=(const Complex& lhs, const double rhs) noexcept { return !(lhs.operator==(Complex(rhs))); }
bool operator!=(const double lhs, const Complex& rhs) noexcept { return !(rhs.operator==(Complex(lhs))); }

Complex operator!(const Complex& rhs) noexcept {
    Complex c;
    c.re = rhs.re;
    c.im = -rhs.im;
    return c;
}

//addition
Complex& Complex::operator+=(const Complex& rhs) noexcept {
	re += rhs.re;
	im += rhs.im;
	return *this;
}
Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }

//subtraction
Complex& Complex::operator-=(const Complex& rhs) noexcept {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}
Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }

//multiplication
Complex& Complex::operator*=(const Complex& rhs) noexcept {
	double temp = re * rhs.re - im * rhs.im;
	im = re * rhs.im + im * rhs.re;
	re = temp;
	return *this;
}
Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }

//division

Complex& Complex::operator/=(const Complex& rhs)
{
    const Complex c0 = { 0,0 };
    try {
        if (rhs == c0) {
            throw std::invalid_argument("Division by zero\n");
        }
        else {
            auto re1 = re, im1 = im;
            re = (re * rhs.re + im * rhs.im) / (std::pow(rhs.re, 2) + std::pow(rhs.im, 2));
            im = (im1 * rhs.re - re1 * rhs.im) / (std::pow(rhs.re, 2) + std::pow(rhs.im, 2));
            return *this;
        }
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
        exit(1);
    }
}
Complex operator/(const Complex& lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }


std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::ReadFrom(std::istream& istrm) noexcept
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);

	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;

	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
