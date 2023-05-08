#include "Fraction.hpp"
#include <algorithm>
#include <cmath>
using namespace ariel;
using namespace std;
#define MAXnumber 1000000

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
    if(num != 0){int val = num*1000;
        int gcd = __gcd(val, 1000);
        this->numerator = val/gcd;
        this->denominator = 1000/gcd;
    }
    else{
        this->numerator =0;
        this->denominator = 1;
    }
    reduce();
}


//***
void add_overflow_check(int a, int b){
    if( a > 0 && b >0 && (a+b)<0){
        throw overflow_error("");
    }
    if( a < 0 && b < 0 && (a+b)>0){
        throw overflow_error("");
    }
}
Fraction Fraction::operator+ (const Fraction& other) const {
    mul_overflow_check(numerator , other.denominator);
    mul_overflow_check(other.numerator , denominator);
    add_overflow_check(numerator * other.denominator, other.numerator * denominator);
    int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    
    mul_overflow_check(numerator , other.denominator);
    mul_overflow_check(other.numerator , denominator);
    add_overflow_check(numerator * other.denominator, -other.numerator * denominator);
    if(other.numerator * -1 == other.numerator && other.numerator != 0){
        throw std::overflow_error("");
    }
    int newnumber = (numerator * other.denominator) - (other.numerator * denominator);
    int newnumber1 = denominator * other.denominator;
    return Fraction(newnumber, newnumber1);
}

void mul_overflow_check(int a, int b){
    if(a == 0 || b == 0 ) return;
    int c = a * b;
    if(c / a != b )
        throw std::overflow_error("");
}

Fraction Fraction::operator*(const Fraction& other) const {
    mul_overflow_check(numerator , other.numerator);
    int n = numerator * other.numerator;
    mul_overflow_check(denominator, other.denominator);
    int d = denominator * other.denominator;
    int gcd = __gcd(n, d);
    return Fraction(n / gcd, d / gcd);
}


Fraction Fraction::operator/(const Fraction& other) const {
    if(other.numerator == 0 ){
        throw std::runtime_error("div by 0");
    }
    mul_overflow_check(numerator , other.denominator);
    int newnumber = numerator * other.denominator;
    mul_overflow_check(denominator , other.numerator);
    int newnumber1 = denominator * other.numerator;
    return Fraction(newnumber, newnumber1);
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


bool ariel::operator>(float frac1, const Fraction& frac2) {
    return frac1 > (float)frac2.getNumerator() / (float)frac2.getDenominator();
}

bool ariel::operator<(float frac1, const Fraction& frac2) {
    return frac1 < (float)frac2.getNumerator() / (float)frac2.getDenominator();
}

bool ariel::operator>=(float frac1, const Fraction& frac2) {
    return frac1 >= (float)frac2.getNumerator() / (float)frac2.getDenominator();
}

bool ariel::operator<=(float frac1, const Fraction& frac2) {
    return frac1 <= (float)frac2.getNumerator() / (float)frac2.getDenominator();
}

bool ariel::operator>(const Fraction& frac2, float frac1) {
    return (float)frac2.numerator / (float)frac2.denominator > frac1;
}

bool ariel::operator<(const Fraction& frac2, float frac1) {
    return (float)frac2.numerator / (float)frac2.denominator < frac1;
}

bool ariel::operator>=(const Fraction& frac2, float frac1) {
    return (float)frac2.numerator / (float)frac2.denominator >= frac1;
}

bool ariel::operator<=(const Fraction& frac2, float frac1) {
    return (float)frac2.numerator / (float)frac2.denominator <= frac1;
}

//***

bool ariel::operator==(const Fraction& frac1, const Fraction& frac2) 
{
    int a = (frac1.numerator * 1000) / frac1.denominator;
    int b = (frac2.numerator * 1000) / frac2.denominator;
    return a == b;
    // return frac1.numerator == frac2.numerator && frac1.denominator == frac2.denominator;
}

Fraction ariel::operator+(float frac1, const Fraction& frac2) {
    return Fraction(frac1) + frac2;
    // return Fraction(frac2.numerator + frac1 * frac2.denominator, frac2.denominator);
}

Fraction ariel::operator-(float frac1, const Fraction& frac2) {
    return Fraction(frac1) - frac2;   
    // return Fraction(frac1 * frac2.denominator - frac2.numerator, frac2.denominator);
}

Fraction ariel::operator*(float frac1, const Fraction& frac2) {
    return Fraction(frac1) * frac2;
}

Fraction ariel::operator/(float frac1, const Fraction& frac2) {
    return Fraction(frac1) / frac2;
    // return Fraction(frac1 * frac2.denominator, frac2.numerator);
}

Fraction ariel::operator+(const Fraction& frac2, float frac1) 
{
    return Fraction(frac1) + frac2;   
    // return Fraction(frac2.numerator + frac1 * frac2.denominator, frac2.denominator);
}

Fraction ariel::operator-(const Fraction& frac2, float frac1) {
    return frac2 - Fraction(frac1);   

    // return Fraction(frac2.numerator - frac1 * frac2.denominator, frac2.denominator);
}

Fraction ariel::operator*(const Fraction& frac2, float frac1) {
        return Fraction(frac1) * frac2;
    }

Fraction ariel::operator/(const Fraction& frac2, float frac1) {
    return frac2 / Fraction(frac1);
    // return Fraction(frac2.numerator, frac2.denominator * frac1);
}

//***

std::ostream& ariel::operator<<(std::ostream& out, const Fraction& f) {
    out << f.getNumerator() << "/" << f.getDenominator();
    return out;
}


std::istream& ariel::operator>>(std::istream& in, Fraction& f) {
    
    int number, number1;
    if(in.peek() == '.'){
        throw std::runtime_error("point error");
    }
    if(in.peek() == EOF)
    {
        throw std::runtime_error("its not number error");
    }
    in >> number;
    cout << number << endl;
    if(in.peek() == '.'){
        throw std::runtime_error("float error");
    }
    
    if(in.peek() == EOF)
    {
        throw std::runtime_error(" one number error");
    }
    in >> number1;
    cout << number1 << endl;
    if(number1 == 0){
        throw runtime_error("div by zero");
    }
    f = Fraction(number, number1);
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


