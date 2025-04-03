#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class Rational {
    private:
        int numerator;
        int denominator;

        static int computeGCD(int a, int b) {
            a = abs(a);
            b = abs(b);
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        void simplify() {
            if (denominator == 0) {
                throw runtime_error("Denominator cannot be zero.");
            }

            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }

            int commonDivisor = computeGCD(numerator, denominator);
            if (commonDivisor != 0) {
                numerator /= commonDivisor;
                denominator /= commonDivisor;
            }
        }

    public:
        Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
            simplify();
        }

        int getNumerator() const { return numerator; }
        int getDenominator() const { return denominator; }

        Rational operator+(const Rational& other) const {
            return Rational(
                numerator * other.denominator + other.numerator * denominator,
                denominator * other.denominator
            );
        }

        Rational operator-(const Rational& other) const {
            return Rational(
                numerator * other.denominator - other.numerator * denominator,
                denominator * other.denominator
            );
        }

        Rational operator*(const Rational& other) const {
            return Rational(
                numerator * other.numerator,
                denominator * other.denominator
            );
        }

        Rational operator/(const Rational& other) const {
            if (other.numerator == 0) {
                throw runtime_error("Attempt to divide by zero.");
            }
            return Rational(
                numerator * other.denominator,
                denominator * other.numerator
            );
        }

        bool operator==(const Rational& other) const {
            return numerator == other.numerator && denominator == other.denominator;
        }

        bool operator!=(const Rational& other) const {
            return !(*this == other);
        }

        bool operator<(const Rational& other) const {
            return numerator * other.denominator < other.numerator * denominator;
        }

        bool operator>(const Rational& other) const {
            return numerator * other.denominator > other.numerator * denominator;
        }

        bool operator<=(const Rational& other) const {
            return *this < other || *this == other;
        }

        bool operator>=(const Rational& other) const {
            return *this > other || *this == other;
        }

        friend ostream& operator<<(ostream& os, const Rational& r) {
            if (r.denominator == 1) {
                os << r.numerator;
            } else {
                os << r.numerator << "/" << r.denominator;
            }
            return os;
        }

        friend istream& operator>>(istream& is, Rational& r) {
            int num, denom = 1;
            char slash;

            is >> num;
            if (is.peek() == '/') {
                is >> slash >> denom;
            }

            r = Rational(num, denom);
            return is;
        }
};


int main() {
    Rational r1(2, 4);  // Fraction 2/4
    Rational r2(3, 6);  // Fraction 3/6

    cout << "Sum of fractions: " << (r1 + r2) << endl;

    return 0;
}