#include "Fraction.hpp"
#include <cmath>

namespace ariel {

    int Fraction::gcd(int a, int b) const {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    void Fraction::reduce() {
        if (numerator == 0) {
            denominator = 1;
        }
        else {
            int gcdValue = gcd(abs(numerator), abs(denominator));
            numerator /= gcdValue;
            denominator /= gcdValue;
        }
    }

    Fraction::Fraction(int numerator, int denominator)
        : numerator(numerator), denominator(denominator)
    {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    Fraction::Fraction(float value) {
        numerator = value * 1000;
        denominator = 1000;
        reduce();
    }
    Fraction::Fraction(double value) {
    numerator = value * 1000;
    denominator = 1000;
    reduce();
}


    int Fraction::getNumerator() const {
        return numerator;
    }

    int Fraction::getDenominator() const {
        return denominator;
    }

    Fraction Fraction::operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction Fraction::operator+(const float& value) const {
        return *this + Fraction(value);
    }

    Fraction operator+(const float& value, const Fraction& frac) {
        return frac + value;
    }

    Fraction Fraction::operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction Fraction::operator-(const float& value) const {
        return *this - Fraction(value);
    }

    Fraction operator-(const float& value, const Fraction& frac) {
        return Fraction(value) - frac;
    }

    Fraction Fraction::operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction Fraction::operator*(const float& value) const {
        return *this * Fraction(value);
    }

    Fraction operator*(const float& value, const Fraction& frac) {
        return frac * value;
    }

    Fraction Fraction::operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    Fraction Fraction::operator/(const float& value) const {
        return *this / Fraction(value);
    }

    Fraction operator/(const float& value, const Fraction& frac) {
        return Fraction(value) / frac;
    }

    bool Fraction::operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool Fraction::operator==(const float& value) const {
        return numerator == round(value * denominator);
    }

    bool operator==(const float& value, const Fraction& frac) {
        return frac == value;
    }

    bool Fraction::operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool Fraction::operator<(const float& value) const {
        return numerator < round(value * denominator);
    }

    bool operator<(const float& value, const Fraction& frac) {
        return frac > value;
    }
    bool Fraction::operator<=(const Fraction& other) const {
    return numerator * other.denominator <= other.numerator * denominator;
    }

    bool Fraction::operator<=(const float& value) const {
        return numerator <= round(value * denominator);
    }

    bool operator<=(const float& value, const Fraction& frac) {
        return frac >= value;
    }

    bool Fraction::operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool Fraction::operator>(const float& value) const {
        return numerator > round(value * denominator);
    }

    bool operator>(const float& value, const Fraction& frac) {
        return frac < value;
    }


    bool Fraction::operator>=(const Fraction& other) const {
        return numerator * other.denominator >= other.numerator * denominator;
    }

    bool Fraction::operator>=(const float& value) const {
        return numerator >= round(value * denominator);
    }
    bool operator>=(const float& value, const Fraction& frac) {
    return frac <= value;
}

    Fraction Fraction::operator++() {
        numerator += denominator;
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp(*this);
        numerator += denominator;
        return temp;
    }

    Fraction Fraction::operator--() {
        numerator -= denominator;
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp(*this);
        numerator -= denominator;
        return temp;
    }

    std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    std::istream& operator>>(std::istream& is, Fraction& fraction) {
        int numerator, denominator;
        char c;
        is >> numerator >> c >> denominator;
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        fraction = Fraction(numerator, denominator);
        return is;
    }

    Fraction::operator float() const {
        return (float)numerator / (float)denominator;
    }


    }


    