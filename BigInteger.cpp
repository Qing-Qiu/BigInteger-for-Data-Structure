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

std::pair<char, BigInteger> BigInteger::sub(BigInteger &a, BigInteger &b) {
    char sgn;
    int comp = cmp(a, b);
    if (comp == -1) {
        swap(a, b);
        sgn = '-';
    } else sgn = '+';
    BigInteger res = *new BigInteger();
    int borrow = 0;
    auto p1 = a.data.tail->prev, p2 = b.data.tail->prev;
    for (int i = 0; i < a.data.size(); i++) {
        res.data.push_front((10 - borrow + p1->val - p2->val) % 10);
        borrow = (p1->val - borrow >= p2->val ? 0 : 1);
        p1 = p1->prev, p2 = p2->prev;
    }
    if (sgn == '-') swap(a, b);
    return {sgn, res};
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
    BigInteger rem = *new BigInteger(a); //余数
    BigInteger tmp = *new BigInteger(b); //除数辅助变量
    BigInteger quo = *new BigInteger(); //商
    auto p = rem.data.head->next;
    auto q = tmp.data.head->next;
    for (int i = 0; i < a.data.size(); i++) {
        if (p->val > 0 || rem.data.size() == 1) break;
        p = p->next;
        rem.data.pop_front();
    }   //被除数（余数）去除前面的0
    for (int i = 0; i < b.data.size(); i++) {
        if (q->val > 0 || tmp.data.size() == 1) break;
        q = q->next;
        tmp.data.pop_front();
    }   //除数去除前面的0
    int d = rem.data.size() - tmp.data.size();
    for (int i = 0; i < d; i++)
        tmp.data.push_back(0);
    //填充除数后面的0，使之跟被除数相同
    for (int i = 0; i < d + 1; i++) {
        int val = 0;
        while (true) {
            auto res = sub(rem, tmp);
            if (res.first == '+') {
                rem = *new BigInteger(res.second);
                val++;
            } else break;
        }
        tmp.data.pop_back();
        tmp.data.push_front(0);
        quo.data.push_back(val);
    }
    return {quo, rem};
}

BigInteger BigInteger::div2(BigInteger &a) {
    BigInteger res = *new BigInteger();
    auto p = a.data.head->next;
    int r = 0;
    bool flag = false;
    for (int i = 0; i < a.data.size(); i++) {
        r = r * 10 + p->val;
        if (r / 2 > 0 || i == a.data.size() - 1) flag = true;
        p = p->next;
        if (!flag) continue;
        res.data.push_back(r / 2);
        r %= 2;
    }
    return res;
}

BigInteger BigInteger::exp(BigInteger &a, BigInteger &b) {
    BigInteger res = *new BigInteger();
    BigInteger two = *new BigInteger();
    res.data.push_back(1);
    two.data.push_back(2);
    while (!isZero(b)) {
        if (b.data.tail->prev->val & 1) res = mul(res, a);
        a = mul(a, a);
        b = div2(b);
//        b = div(b, two).first;
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

void BigInteger::displayAll() {
    data.displayAll();
}

void BigInteger::fileDisplay() {
    data.fileDisplay();
}

void BigInteger::displayLen(std::string io) {
    data.displayLen(io);
}

#endif //BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_CPP
