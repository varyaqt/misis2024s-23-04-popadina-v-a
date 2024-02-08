#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <string>
#include <stdexcept>

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

class Rational {
public:
    Rational() = default;
    Rational(const Rational&) = default;
    explicit Rational(const int64_t num) : Rational(num, 1) {}
    Rational(const int64_t num, const int64_t den);
    ~Rational() = default;
    int64_t num() const {
        return num_;
    }
    int64_t den() const {
        return den_;
    }
    Rational& operator=(const Rational& r) = default;
    Rational& operator*=(const Rational& r) noexcept;
    Rational& operator*=(const int64_t d) noexcept { return operator*=(Rational(d)); }
    Rational& operator+=(const Rational& r) noexcept;
    Rational& operator+=(const int64_t d) noexcept { return operator+=(Rational(d)); }
    Rational& operator-=(const Rational& r) noexcept;
    Rational& operator-=(const int64_t d) noexcept { return operator-=(Rational(d)); }
    Rational& operator/=(const Rational& r);
    Rational& operator/=(const int64_t d) { return operator/=(Rational(d)); }

    int64_t evkl(const Rational& r) noexcept { return evkl(r.num_, r.den_); }
    int64_t evkl(const int64_t c1, const int64_t c2) noexcept;

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
	static const char separator{ '/' };
	
private:
	int64_t num_ = 0;
	int64_t den_ = 1;
};

Rational operator+(const Rational& r1, const Rational& r2) noexcept;
Rational operator+(const Rational& r1, const int64_t c) noexcept;
Rational operator+(const int64_t c, const Rational& r2) noexcept;
Rational operator-(const Rational& r1, const Rational& r2) noexcept;
Rational operator-(const Rational& r1, const int64_t c) noexcept;
Rational operator-(const int64_t c, const Rational& r2) noexcept;
Rational operator*(const Rational& r1, const Rational& r2) noexcept;
Rational operator*(const Rational& r1, const int64_t c) noexcept;
Rational operator*(const int64_t c, const Rational& r2) noexcept;
Rational operator/(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const int64_t c);
Rational operator/(const int64_t c, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2) noexcept;
bool operator==(const int64_t c, const Rational& r2) noexcept;
bool operator==(const Rational& r1, const int64_t c) noexcept;
bool operator!=(const Rational& r1, const Rational& r2) noexcept;
bool operator!=(const int64_t c, const Rational& r2) noexcept;
bool operator!=(const Rational& r1, const int64_t c) noexcept;
bool operator>(const Rational& r1, const Rational& r2) noexcept;
bool operator>(const int64_t c, const Rational& r2) noexcept;
bool operator>(const Rational& r1, const int64_t c) noexcept;
bool operator<(const Rational& r1, const Rational& r2) noexcept;
bool operator<(const int64_t c, const Rational& r2) noexcept;
bool operator<(const Rational& r1, const int64_t c) noexcept;
bool operator>=(const Rational& r1, const Rational& r2) noexcept;
bool operator>=(const int64_t c, const Rational& r2) noexcept;
bool operator>=(const Rational& r1, const int64_t c) noexcept;
bool operator<=(const Rational& r1, const Rational& r2) noexcept;
bool operator<=(const int64_t c, const Rational& r2) noexcept;
bool operator<=(const Rational& r1, const int64_t c) noexcept;

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
    return rhs.readFrom(istrm);
}

#endif
