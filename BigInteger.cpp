#ifndef BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_CPP
#define BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_CPP

#include "BigInteger.h"

BigInteger::BigInteger() : data() {
}

BigInteger::BigInteger(std::string str) {
    data = *new List(str);
}

BigInteger BigInteger::add(const BigInteger &a, const BigInteger &b) {
    BigInteger res = *new BigInteger();
    int carry = 0;
    if (a.data.size() < b.data.size()) {

    } else {

    }
    return a;
}

BigInteger BigInteger::sub(const BigInteger &a, const BigInteger &b) {

}

BigInteger BigInteger::mul(const BigInteger &a, const BigInteger &b) {

}

std::pair<BigInteger, BigInteger> BigInteger::div(const BigInteger &a, const BigInteger &b) {

}

BigInteger BigInteger::exp(const BigInteger &a, const BigInteger &b) {

}

void BigInteger::display() {
    data.display();
}

#endif //BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_CPP
