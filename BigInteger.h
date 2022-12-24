#ifndef BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_H
#define BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_H

#include "List.h"
#include <cmath>
#include <cstring>

struct Complex {
    double x, y;

    Complex operator+(const Complex &t) const {
        return {x + t.x, y + t.y};
    }

    Complex operator-(const Complex &t) const {
        return {x - t.x, y - t.y};
    }

    Complex operator*(const Complex &t) const {
        return {x * t.x - y * t.y, x * t.y + y * t.x};
    }
};

class BigInteger {
public:
    BigInteger();

    BigInteger(const std::string &str);

    static int cmp(const BigInteger &a, const BigInteger &b);

    static void swap(BigInteger &a, BigInteger &b);

    static BigInteger add(const BigInteger &a, const BigInteger &b);

    static std::pair<char, BigInteger> sub(BigInteger &a, BigInteger &b);

    static BigInteger mul(const BigInteger &a, const BigInteger &b);

    static BigInteger exmul(const BigInteger &a, const BigInteger &b);

    static void FFT(Complex para[], int);

    static std::pair<BigInteger, BigInteger> div(const BigInteger &a, const BigInteger &b);

    static BigInteger div2(BigInteger &a);

    static BigInteger exp(BigInteger &a, BigInteger &b);

    static BigInteger exexp(BigInteger &a, BigInteger &b);

    static bool isZero(BigInteger &a);

    void display();

    void displayAll();

    void fileDisplay();

    void displayLen(std::string);

private:
    List data;
};

#endif //BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_H
