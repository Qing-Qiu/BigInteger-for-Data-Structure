#ifndef BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_CPP
#define BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_CPP

#include "BigInteger.h"

BigInteger::BigInteger() : data() {
}

BigInteger::BigInteger(const std::string &str) {
    data = *new List(str);
}

BigInteger BigInteger::add(const BigInteger &a, const BigInteger &b) {
    BigInteger res = *new BigInteger();
    int carry = 0;
    auto h1 = a.data.tail->prev, h2 = b.data.tail->prev;
    for (int i = 0; i < a.data.size(); i++) {
        res.data.push_front((h1->val + h2->val + carry) % 10);
        carry = (h1->val + h2->val + carry) / 10;
        h1 = h1->prev, h2 = h2->prev;
    }
    return res;
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
