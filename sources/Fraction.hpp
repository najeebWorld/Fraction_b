#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
void mul_overflow_check(int num1, int num2);
void add_overflow_check(int num1, int num2);
namespace ariel {
    
    class Fraction {
        private:
            int numerator;      // The numerator of the fraction
            int denominator;    // The denominator of the fraction
            int gcd(int num1, int num2) const;
            void reduce();
        
        public:
            void setNumerator(int n);
            void setDenomirator(int n);
            // Constructors
            Fraction();
            Fraction(int numerator, int denominator);
            Fraction(float num);
            //Fraction(const Fraction& other) noexcept;//copy 

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

            friend bool operator== (const Fraction& fraction1, const Fraction& fraction2);
            friend Fraction operator+ (float fraction1, const Fraction& fraction2);
            friend Fraction operator- (float fraction1, const Fraction& fraction2);
            friend Fraction operator* (float fraction1, const Fraction& fraction2);
            friend Fraction operator/ (float fraction1, const Fraction& fraction2);
            friend Fraction operator+ (const Fraction& fraction2, float fraction1);
            friend Fraction operator- (const Fraction& fraction2, float fraction1);
            friend Fraction operator* (const Fraction& fraction2, float fraction1);
            friend Fraction operator/ (const Fraction& fraction2, float fraction1);

            friend bool operator> (float fraction1, const Fraction& fraction2);
            friend bool operator< (float fraction1, const Fraction& fraction2);
            friend bool operator>= (float fraction1, const Fraction& fraction2);
            friend bool operator<= (float fraction1, const Fraction& fraction2);
            friend bool operator> (const Fraction& fraction2, float fraction1);
            friend bool operator< (const Fraction& fraction2, float fraction1);
            friend bool operator>= (const Fraction& fraction2, float fraction1);
            friend bool operator<= (const Fraction& fraction2, float fraction1);

            

            friend std::ostream& operator<< (std::ostream& output, const Fraction& fow);
            friend std::istream& operator>> (std::istream& input, Fraction& flow);

            int getNumerator() const;
            int getDenominator() const;
            
    };

    
}

