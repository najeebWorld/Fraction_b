#include "Fraction.hpp"
#include <algorithm>
#include <cmath>
using namespace ariel;
using namespace std;
#define MAX_NUM 1000000

int Fraction::gcd(int a, int b) const {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void Fraction::reduce() {
    if (this->numerator == 0) {
        this->denominator = 1;
    }
    else {
            
        int gc = __gcd(abs(this->numerator), abs(this->denominator));
        this->numerator /= gc;
        this->denominator /= gc;
        if (this->denominator < 0) {
        this->numerator *= -1;
        this->denominator *= -1;
    }
    }}
Fraction::Fraction(){
    this->denominator = 1;
    this->numerator = 1;
}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator){
    if(denominator == 0){
        throw invalid_argument("Fraction can't be divided by zero");
    }
    reduce();
}

Fraction::Fraction(float num){
    // Convert the float to a fraction
    int val = num*1000;
    int gcd = __gcd(val, 1000);
    this->numerator = val/gcd;
    this->denominator = 1000/gcd;
}

Fraction::Fraction(const Fraction& other) noexcept : numerator(other.numerator), denominator(other.denominator) {}

//***

Fraction Fraction::operator+ (const Fraction& other) const {
    int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int new_num = (numerator * other.denominator) - (other.numerator * denominator);
    int new_den = denominator * other.denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int n = numerator * other.numerator;
    int d = denominator * other.denominator;
    int gcd = __gcd(n, d);
    return Fraction(n / gcd, d / gcd);
}

Fraction Fraction::operator/(const Fraction& other) const {
    int new_num = numerator * other.denominator;
    int new_den = denominator * other.numerator;
    return Fraction(new_num, new_den);
}
//***
Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

const Fraction Fraction::operator++(int value) {
    Fraction old_val = *this;
    numerator += denominator;
    return old_val;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

const Fraction Fraction::operator--(int value) {
    Fraction old_val = *this;
    numerator -= denominator;
    return old_val;
}

//***

bool Fraction::operator>(const Fraction& other) const {
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Fraction::operator<(const Fraction& other) const {
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Fraction::operator>=(const Fraction& other) const {
    return (numerator * other.denominator) >= (other.numerator * denominator);
}

bool Fraction::operator<=(const Fraction& other) const {
    return (numerator * other.denominator) <= (other.numerator * denominator);
}

//***

Fraction& Fraction::operator=(const Fraction& other) noexcept {
    if (this != &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    return *this;
}
//***

bool ariel::operator>(float f1, const Fraction& f2) {
    return f1 > (float)f2.getNumerator() / (float)f2.getDenominator();
}

bool ariel::operator<(float f1, const Fraction& f2) {
    return f1 < (float)f2.getNumerator() / (float)f2.getDenominator();
}

bool ariel::operator>=(float f1, const Fraction& f2) {
    return f1 >= (float)f2.getNumerator() / (float)f2.getDenominator();
}

bool ariel::operator<=(float f1, const Fraction& f2) {
    return f1 <= (float)f2.getNumerator() / (float)f2.getDenominator();
}

bool ariel::operator>(const Fraction& f2, float f1) {
    return (float)f2.numerator / (float)f2.denominator > f1;
}

bool ariel::operator<(const Fraction& f2, float f1) {
    return (float)f2.numerator / (float)f2.denominator < f1;
}

bool ariel::operator>=(const Fraction& f2, float f1) {
    return (float)f2.numerator / (float)f2.denominator >= f1;
}

bool ariel::operator<=(const Fraction& f2, float f1) {
    return (float)f2.numerator / (float)f2.denominator <= f1;
}

//***

bool ariel::operator==(const Fraction& f1, const Fraction& f2) {
    return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
}

Fraction ariel::operator+(float f1, const Fraction& f2) {
    return Fraction(f2.numerator + f1 * f2.denominator, f2.denominator);
}

Fraction ariel::operator-(float f1, const Fraction& f2) {
    return Fraction(f1 * f2.denominator - f2.numerator, f2.denominator);
}

Fraction ariel::operator*(float f1, const Fraction& f2) {
    int n = f1 * f2.numerator;
    int d = f2.denominator;
    int gcd = __gcd(n, d);
    return Fraction(n / gcd, d / gcd);
}

Fraction ariel::operator/(float f1, const Fraction& f2) {
    return Fraction(f1 * f2.denominator, f2.numerator);
}

Fraction ariel::operator+(const Fraction& f2, float f1) {
    return Fraction(f2.numerator + f1 * f2.denominator, f2.denominator);
}

Fraction ariel::operator-(const Fraction& f2, float f1) {
    return Fraction(f2.numerator - f1 * f2.denominator, f2.denominator);
}

Fraction ariel::operator*(const Fraction& f2, float f1) {
    int n = round(f1 * f2.numerator);
    int d = f2.denominator;
    int gcd = __gcd(n, d);
    return Fraction(n / gcd, d / gcd);
    }

Fraction ariel::operator/(const Fraction& f2, float f1) {
    return Fraction(f2.numerator, f2.denominator * f1);
}

//***

std::ostream& ariel::operator<<(std::ostream& out, const Fraction& f) {
    out << f.getNumerator() << "/" << f.getDenominator();
    return out;
}


std::istream& ariel::operator>>(std::istream& in, Fraction& f) {
    int _num, _den;
    if(in.peek() == EOF)
    {
        throw("not a number error");
    }
    in >> _num;
    if(in.peek() == EOF)
    {
        throw("only one number error");
    }
    in >> _den;
    f.setNumerator(_num);
    f.setDenomirator(_den);
    return in;
}

int Fraction::getNumerator() const {
    return this->numerator;
}

int Fraction::getDenominator() const {
    return this->denominator;
}

void Fraction::setNumerator(int n){
    this->numerator = n;
}

void Fraction::setDenomirator(int n){
    this->denominator = n;
}



















