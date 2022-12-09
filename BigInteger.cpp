#ifndef BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_CPP
#define BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_CPP

#include "BigInteger.h"

BigInteger::BigInteger() : data() {
}

BigInteger::BigInteger(const std::string &str) {
    data = *new List(str);
}

int BigInteger::cmp(const BigInteger &a, const BigInteger &b) {
    auto p1 = a.data.head->next, p2 = b.data.head->next;
    for (int i = 0; i < a.data.size(); i++) {
        if (p1->val > p2->val) return 1;
        if (p1->val < p2->val) return -1;
        p1 = p1->next, p2 = p2->next;
    }
    return 0;
}

void BigInteger::swap(BigInteger &a, BigInteger &b) {
    auto p1 = a.data.head->next, p2 = b.data.head->next;
    for (int i = 0; i < a.data.size(); i++) {
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
        p1 = p1->next, p2 = p2->next;
    }
}

BigInteger BigInteger::add(const BigInteger &a, const BigInteger &b) {
    BigInteger res = *new BigInteger();
    int carry = 0;
    auto p1 = a.data.tail->prev, p2 = b.data.tail->prev;
    for (int i = 0; i < a.data.size(); i++) {
        res.data.push_front((p1->val + p2->val + carry) % 10);
        carry = (p1->val + p2->val + carry) / 10;
        p1 = p1->prev, p2 = p2->prev;
    }
    return res;
}

BigInteger BigInteger::sub(BigInteger &a, BigInteger &b) {
    if (cmp(a, b) == -1) {
        swap(a, b);
        std::cout << '-';
    }
    BigInteger res = *new BigInteger();
    int borrow = 0;
    auto p1 = a.data.tail->prev, p2 = b.data.tail->prev;
    for (int i = 0; i < a.data.size(); i++) {
        res.data.push_front((10 - borrow + p1->val - p2->val) % 10);
        borrow = (p1->val - borrow >= p2->val ? 0 : 1);
        p1 = p1->prev, p2 = p2->prev;
    }
    return res;
}

BigInteger BigInteger::mul(const BigInteger &a, const BigInteger &b) {
    BigInteger res = *new BigInteger();
    for (int i = 0; i < a.data.size() + b.data.size(); i++)
        res.data.push_back(0);
    auto base = res.data.tail->prev;
    auto p1 = a.data.tail->prev;
    for (int i = 0; i < a.data.size(); i++) {
        auto p = base;
        auto p2 = b.data.tail->prev;
        for (int j = 0; j < b.data.size(); j++) {
            p->val += p1->val * p2->val;
            p = p->prev;
            p2 = p2->prev;
        }
        p1 = p1->prev;
        base = base->prev;
    }
    int carry = 0;
    auto p = res.data.tail->prev;
    for (int i = 0; i < res.data.size(); i++) {
        carry += p->val;
        p->val = carry % 10;
        carry /= 10;
        p = p->prev;
    }
    return res;
}

std::pair<BigInteger, BigInteger> BigInteger::div(const BigInteger &a, const BigInteger &b) {
    BigInteger res = *new BigInteger();
}

BigInteger BigInteger::exp(BigInteger &a, BigInteger &b) {
    BigInteger res = *new BigInteger();
    BigInteger two = *new BigInteger();
    two.data.push_back(2);
    while (!isZero(b)) {
        if (b.data.tail->prev->val & 1) res = mul(res, a);
        a = mul(a, a);
        b = div(b, two).first;
    }
    return res;
}

bool BigInteger::isZero(BigInteger &a) {
    auto p1 = a.data.head->next;
    while (p1 != a.data.tail) {
        if (p1->val != 0) return false;
        p1 = p1->next;
    }
    return true;
}

void BigInteger::display() {
    data.display();
}

#endif //BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_CPP
