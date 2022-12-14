#ifndef BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_H
#define BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_H

#include "List.h"

class BigInteger {
public:
    BigInteger();

    BigInteger(const std::string &str);

    static int cmp(const BigInteger &a, const BigInteger &b);

    static void swap(BigInteger &a, BigInteger &b);

    static BigInteger add(const BigInteger &a, const BigInteger &b);

    static std::pair<char,BigInteger> sub(BigInteger &a, BigInteger &b);

    static BigInteger mul(const BigInteger &a, const BigInteger &b);

    static std::pair<BigInteger, BigInteger> div(const BigInteger &a, const BigInteger &b);

    static BigInteger exp(BigInteger &a, BigInteger &b);

    static bool isZero(BigInteger &a);

    void display();

    void displayAll();

private:
    List data;
};

#endif //BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_H
