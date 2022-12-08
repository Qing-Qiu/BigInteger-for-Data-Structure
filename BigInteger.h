#ifndef BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_H
#define BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_H

#include "List.h"

class BigInteger {
public:
    BigInteger();

    BigInteger(std::string str);

    static BigInteger add(const BigInteger &a, const BigInteger &b);

    static BigInteger sub(const BigInteger &a, const BigInteger &b);

    static BigInteger mul(const BigInteger &a, const BigInteger &b);

    static std::pair<BigInteger, BigInteger> div(const BigInteger &a, const BigInteger &b);

    static BigInteger exp(const BigInteger &a, const BigInteger &b);

    void display();

private:
    List data;
};

#endif //BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_H
