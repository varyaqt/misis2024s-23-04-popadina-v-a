#include <rational/rational.hpp>

Rational operator+(const Rational& r1, const int64_t c) noexcept { return operator+(r1, Rational(c)); }
Rational operator+(const int64_t c, const Rational& r2) noexcept { return operator+(Rational(c), r2); }
Rational operator-(const Rational& r1, const int64_t c) noexcept { return operator-(r1, Rational(c)); }
Rational operator-(const int64_t c, const Rational& r2) noexcept { return operator-(Rational(c), r2); }
Rational operator*(const Rational& r1, const int64_t c) noexcept { return operator*(r1, Rational(c)); }
Rational operator*(const int64_t c, const Rational& r2) noexcept { return operator*(Rational(c), r2); }
Rational operator/(const Rational& r1, const int64_t c) { return operator/(r1, Rational(c)); }
Rational operator/(const int64_t c, const Rational& r2) { return operator/(Rational(c), r2); }
bool operator==(const int64_t c, const Rational& r2) noexcept { return operator==(Rational(c), r2); }
bool operator==(const Rational& r1, const int64_t c) noexcept { return operator==(r1, Rational(c)); }
bool operator!=(const Rational& r1, const Rational& r2) noexcept { return !operator==(r1, r2); }
bool operator!=(const int64_t c, const Rational& r2) noexcept { return !operator==(Rational(c), r2); }
bool operator!=(const Rational& r1, const int64_t c) noexcept { return !operator==(r1, Rational(c)); }
bool operator>(const int64_t c, const Rational& r2) noexcept { return operator>(Rational(c), r2); }
bool operator>(const Rational& r1, const int64_t c) noexcept { return operator>(r1, Rational(c)); }
bool operator<(const int64_t c, const Rational& r2) noexcept { return !operator>(Rational(c), r2); }
bool operator<(const Rational& r1, const int64_t c) noexcept { return !operator>(r1, Rational(c)); }
bool operator>=(const Rational& r1, const Rational& r2) noexcept { return !operator<(r1, r2); }
bool operator>=(const int64_t c, const Rational& r2) noexcept { return operator>=(Rational(c), r2); }
bool operator>=(const Rational& r1, const int64_t c) noexcept { return operator>=(r1, Rational(c)); }
bool operator<=(const Rational& r1, const Rational& r2) noexcept { return !operator>(r1, r2); }
bool operator<=(const int64_t c, const Rational& r2) noexcept { return operator<=(Rational(c), r2); }
bool operator<=(const Rational& r1, const int64_t c) noexcept { return operator<=(r1, Rational(c)); }

bool operator==(const Rational& r1, const Rational& r2) noexcept {
    int64_t ch1 = r1.num() * r2.den();
    int64_t ch2 = r2.num() * r1.den();
    return ch1 == ch2;
}
bool operator>(const Rational& r1, const Rational& r2) noexcept {
    int64_t ch1 = r1.num() * r2.den();
    int64_t ch2 = r2.num() * r1.den();
    return ch1 > ch2;
}
bool operator<(const Rational& r1, const Rational& r2) noexcept {
    int64_t ch1 = r1.num() * r2.den();
    int64_t ch2 = r2.num() * r1.den();
    return ch1 < ch2;
}

int64_t Rational::evkl(const int64_t c1, const int64_t c2) noexcept {
    int64_t mx, mn;
    int64_t v;
    mx = std::max(std::abs(c1), std::abs(c2));
    mn = std::min(std::abs(c1), std::abs(c2));
    if (mn == 0) {
        return mx;
    }
    while (mx != mn) {
        mx = mx - mn;
        v = mx;
        mx = std::max(mx, mn);
        mn = std::min(v, mn);
    }
    return mx;
}

Rational::Rational(const int64_t num, const int64_t den) {
    num_ = num;
    den_ = den;
    if (den_ == 0) {
        throw std::invalid_argument("Zero denumenator");
    }
    else {
        int64_t nod = evkl(num_, den_);
        num_ /= nod;
        den_ /= nod;
    } 
}

Rational& Rational::operator+=(const Rational& r) noexcept {
    num_ = num_ * r.den_ + den_ * r.num_;
    den_ *= r.den_;
    int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    return *this;
}
Rational& Rational::operator-=(const Rational& r) noexcept {
    num_ = num_ * r.den_ - den_ * r.num_;
    den_ *= r.den_;
    int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    return *this;
}

Rational& Rational::operator*=(const Rational& r) noexcept {
    num_ *= r.num_;
    den_ *= r.den_;
    int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    return *this;
}

Rational& Rational::operator/=(const Rational& r) {
    if (r.num_ == 0) {
        throw std::invalid_argument("Division by zero");
    }
    num_ *= r.den_;
    den_ *= r.num_;
    int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    return *this;
}

Rational operator+(const Rational& r1, const Rational& r2) noexcept {
    Rational r11(r1);
    r11 += r2;
    return r11;
}

Rational operator-(const Rational& r1, const Rational& r2) noexcept {
    Rational r11(r1);
    r11 -= r2;
    return r11;
}

Rational operator*(const Rational& r1, const Rational& r2) noexcept {
    Rational r11(r1);
    r11 *= r2;
    return r11;
}

Rational operator/(const Rational& r1, const Rational& r2) {
    Rational r11(r1);
    r11 /= r2;
    return r11;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << num_ << separator << den_;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
    char separator(0);
    int64_t num(0);
    int64_t den(0);
    istrm >> num >> separator >> den;
    if (istrm.good())
    {
        if ((Rational::separator == separator))
        {
            num_ = num;
            den_ = den;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
