#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

class Polynomial;

class PolynomialUtils {
    public:
        static int evaluate(const Polynomial& p, int x);
        static Polynomial derivative(const Polynomial& p);

};

class Polynomial {
    private:
        vector<int> coefficients;

        void removeTrailingZeros() {
            while (coefficients.size() > 1 && coefficients.back() == 0) {
                coefficients.pop_back();
            }
        }

    public:
        Polynomial() = default;

        Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
            removeTrailingZeros();
        }

        const vector<int>& getCoefficients() const { return coefficients; }

        Polynomial operator+(const Polynomial& other) const {
            vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);

            for (size_t i = 0; i < coefficients.size(); ++i) {
                result[i] += coefficients[i];
            }

            for (size_t i = 0; i < other.coefficients.size(); ++i) {
                result[i] += other.coefficients[i];
            }

            return Polynomial(result);
        }

        Polynomial operator-(const Polynomial& other) const {
            vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);

            for (size_t i = 0; i < coefficients.size(); ++i) {
                result[i] += coefficients[i];
            }

            for (size_t i = 0; i < other.coefficients.size(); ++i) {
                result[i] -= other.coefficients[i];
            }

            return Polynomial(result);
        }

        Polynomial operator*(const Polynomial& other) const {
            vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);

            for (size_t i = 0; i < coefficients.size(); ++i) {
                for (size_t j = 0; j < other.coefficients.size(); ++j) {
                    result[i + j] += coefficients[i] * other.coefficients[j];
                }
            }

            return Polynomial(result);
        }

        friend ostream& operator<<(ostream& os, const Polynomial& p) {
            if (p.coefficients.empty()) {
                os << "0";
                return os;
            }

            bool firstTerm = true;

            for (int i = p.coefficients.size() - 1; i >= 0; --i) {
                int coeff = p.coefficients[i];

                if (coeff == 0) continue;

                if (!firstTerm) {
                    os << (coeff > 0 ? " + " : " - ");
                } else if (coeff < 0) {
                    os << "-";
                }

                int absCoeff = abs(coeff);

                if (absCoeff != 1 || i == 0) {
                    if (!firstTerm) os << absCoeff;
                    else os << coeff;
                }

                if (i > 0) {
                    os << "x";
                    if (i > 1) {
                        os << "^" << i;
                    }
                }

                firstTerm = false;
            }

            return os;
        }

        friend class PolynomialUtils;
};


int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0;
    for (int i = p.coefficients.size() - 1; i >= 0; --i) {
        result = result * x + p.coefficients[i];
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    if (p.coefficients.size() <= 1) return Polynomial({0});

    vector<int> deriv(p.coefficients.size() - 1);
    for (size_t i = 1; i < p.coefficients.size(); ++i) {
        deriv[i-1] = p.coefficients[i] * i;
    }
    return Polynomial(deriv);
}


int main() {
    Polynomial poly1({5, -2, 4});
    Polynomial poly2({-3, 7, 1});

    cout << "Polynomial 1: " << poly1 << endl;
    cout << "Polynomial 2: " << poly2 << endl;
    cout << "Sum: " << poly1 + poly2 << endl;
    cout << "Product: " << poly1 * poly2 << endl;
    cout << "Evaluating poly1 at x = 4: " << PolynomialUtils::evaluate(poly1, 4) << endl;
    cout << "Derivative of poly2: " << PolynomialUtils::derivative(poly2) << endl;

    return 0;
}