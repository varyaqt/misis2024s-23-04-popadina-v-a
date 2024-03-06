#include "complex/complex.hpp"

Complex::Complex(const double real)
	: Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{
}

//addition
Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}
Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }

//subtraction
Complex& Complex::operator-=(const Complex& rhs) {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}
Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }

//multiplication
Complex& Complex::operator*=(const Complex& rhs) {
	double temp = re * rhs.re - im * rhs.im;
	im = re * rhs.im + im * rhs.re;
	re = temp;
	return *this;
}
Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }

//division
Complex& Complex::operator/=(const Complex& rhs) {
	double temp = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	im = (rhs.re * im - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	re = temp;
	return *this;
}
Complex operator/(const Complex& lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }

//conjugate
Complex conjugate(Complex& c) {
	Complex cc(c.re, -1 * c.im);
	return cc;
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::ReadFrom(std::istream& istrm)
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
