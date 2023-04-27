
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
namespace ariel{

    class Fraction{

        private:
            int numerator;
            int denominator;

            int gcd(int a, int b) const;
            void reduce();

        public:
            Fraction(int numerator = 0, int denominator = 1);
            Fraction(float value);
            Fraction(double value);

            int getNumerator() const;
            int getDenominator() const;

            Fraction operator+(const Fraction& other) const;
            Fraction operator+(const float& value) const;
            friend Fraction operator+(const float& value, const Fraction& frac);

            Fraction operator-(const Fraction& other) const;
            Fraction operator-(const float& value) const;
            friend Fraction operator-(const float& value, const Fraction& frac);

            Fraction operator*(const Fraction& other) const;
            Fraction operator*(const float& value) const;
            friend Fraction operator*(const float& value, const Fraction& frac);

            Fraction operator/(const Fraction& other) const;
            Fraction operator/(const float& value) const;
            friend Fraction operator/(const float& value, const Fraction& frac);

            bool operator==(const Fraction& other) const;
            bool operator==(const float& value) const;
            friend bool operator==(const float& value, const Fraction& frac);

            bool operator<(const Fraction& other) const;
            bool operator<(const float& value) const;
            friend bool operator<(const float& value, const Fraction& frac);

            bool operator<=(const Fraction& other) const;
            bool operator<=(const float& value) const;
            friend bool operator<=(const float& value, const Fraction& frac);

            bool operator>(const Fraction& other) const;
            bool operator>(const float& value) const;
            friend bool operator>(const float& value, const Fraction& frac);

            bool operator>=(const Fraction& other) const;
            bool operator>=(const float& value) const;
            friend bool operator>=(const float& value, const Fraction& frac);

            Fraction operator++(); //prefix
            Fraction operator++(int); //postfix
            Fraction operator--(); //prefix
            Fraction operator--(int); //postfix

            friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& is, Fraction& fraction);

            explicit operator float() const;
    };

}

#endif  // FRACTION_H