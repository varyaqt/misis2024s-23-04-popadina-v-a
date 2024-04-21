#pragma once
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iosfwd>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <stdexcept>

struct Complex {
	Complex() {}
	[[nodiscard]] Complex() = default;
	[[nodiscard]] Complex(const Complex&) = default;
	[[nodiscard]]  Complex(Complex&&) = default;
	~Complex() = default;
	[[nodiscard]] explicit Complex(const double real) : Complex (real, 0.0) { }
	[[nodiscard]] Complex(const double real, const double imaginary) : re(real), im(imaginary) {}
	Complex& operator=(const Complex&) = default;
	Complex& operator=(Complex&&) = default;
	[[nodiscard]] bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
	[[nodiscard]] bool operator==(const double rhs) const { return operator==(Complex(rhs)); }
	[[nodiscard]] bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	[[nodiscard]] bool operator!=(const double rhs) const { return operator!=(Complex(rhs)); }

	Complex& operator=(const Complex& rhs) = default;
	Complex& operator=(Complex&&) = default;
	Complex& operator+=(const Complex& rhs) noexcept;
	Complex& operator+=(const double rhs) noexcept {
		return operator+=(Complex(rhs));
	}

	Complex& operator-=(const Complex& rhs) noexcept;
	Complex& operator-=(const double rhs) noexcept {
		return operator-=(Complex(rhs));
	}

	Complex& operator*=(const Complex& rhs) noexcept;
	Complex& operator*=(const double rhs) noexcept {
		return operator*=(Complex(rhs));
	}

	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) {
		return operator/=(Complex(rhs));
	}
	[[nodiscard]] Complex operator-() const noexcept;
	void conjugate() { im = -im; }

	[[nodiscard]] std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
	[[nodiscard]] std::istream& ReadFrom(std::istream& istrm) noexcept;

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };   
	static const char separator{ ',' };   
	static const char rightBrace{ '}' };
};

[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator+(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator+(const double lhs, const Complex& rhs) noexcept;

[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator-(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator-(const double lhs, const Complex& rhs) noexcept;

[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator*(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator*(const double lhs, const Complex& rhs) noexcept;

[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator/(const Complex& lhs, const double rhs);
[[nodiscard]] Complex operator/(const double lhs, const Complex& rhs);


[[nodiscard]] Complex pow(const Complex& lhs, int n);

[[nodiscard]] double abs(const Complex& rhs) noexcept;

void test(const Complex& c1, const Complex& c2, const double c) {};
bool testParse(const std::string& str);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
	return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
	return rhs.ReadFrom(istrm);
}

#endif
