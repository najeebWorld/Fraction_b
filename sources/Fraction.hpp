#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
void mul_overflow_check(int a, int b);
void add_overflow_check(int a, int b);
namespace ariel {
    
    class Fraction {
        private:
            int numerator;      // The numerator of the fraction
            int denominator;    // The denominator of the fraction
            int gcd(int a, int b) const;
            void reduce();
        
        public:
            void setNumerator(int n);
            void setDenomirator(int n);
            // Constructors
            Fraction();
            Fraction(int numerator, int denominator);
            Fraction(float num);
            Fraction(const Fraction& other) noexcept;//copy 

            Fraction operator+ (const Fraction& other) const;
            Fraction operator- (const Fraction& other) const;
            Fraction operator* (const Fraction& other) const;
            Fraction operator/ (const Fraction& other) const;

            Fraction& operator++ ();
            const Fraction operator++ (int value);
            Fraction& operator-- ();
            const Fraction operator-- (int value);

            bool operator> (const Fraction& other) const;
            bool operator< (const Fraction& other) const;
            bool operator>= (const Fraction& other) const;
            bool operator<= (const Fraction& other) const;

            Fraction& operator= (const Fraction& other) noexcept;

            friend bool operator> (float f1, const Fraction& f2);
            friend bool operator< (float f1, const Fraction& f2);
            friend bool operator>= (float f1, const Fraction& f2);
            friend bool operator<= (float f1, const Fraction& f2);
            friend bool operator> (const Fraction& f2, float f1);
            friend bool operator< (const Fraction& f2, float f1);
            friend bool operator>= (const Fraction& f2, float f1);
            friend bool operator<= (const Fraction& f2, float f1);

            friend bool operator== (const Fraction& f1, const Fraction& f2);
            friend Fraction operator+ (float f1, const Fraction& f2);
            friend Fraction operator- (float f1, const Fraction& f2);
            friend Fraction operator* (float f1, const Fraction& f2);
            friend Fraction operator/ (float f1, const Fraction& f2);
            friend Fraction operator+ (const Fraction& f2, float f1);
            friend Fraction operator- (const Fraction& f2, float f1);
            friend Fraction operator* (const Fraction& f2, float f1);
            friend Fraction operator/ (const Fraction& f2, float f1);

            friend std::ostream& operator<< (std::ostream& output, const Fraction& f);
            friend std::istream& operator>> (std::istream& input, Fraction& f);

            int getNumerator() const;
            int getDenominator() const;
            
    };

    float FractionToFloat(const Fraction& a);

}

