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
    char sgn = '+';
    if (cmp(a, b) == -1) {
        swap(a, b);
        sgn = '-';
    }
    BigInteger res = *new BigInteger();
    int borrow = 0;
    auto p1 = a.data.tail->prev, p2 = b.data.tail->prev;
    for (int i = 0; i < a.data.size(); i++) {
        res.data.push_front((10 - borrow + p1->val - p2->val) % 10);
        borrow = (p1->val - borrow >= p2->val ? 0 : 1);
        p1 = p1->prev, p2 = p2->prev;
    }
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
    BigInteger quo = *new BigInteger();
    BigInteger rem = *new BigInteger(a);
    BigInteger tmp = *new BigInteger(b);
    int lenA = a.data.size(), lenB = b.data.size();
    auto p1 = a.data.head->next, p2 = b.data.head->next;
    auto p = rem.data.head->next;
    auto q = tmp.data.head->next;
    for (int i = 0; i < a.data.size(); i++) {
        if (p1->val > 0 || lenA == 1) break;
        p1 = p1->next;
        p = p->next;
        lenA--;
    }
    for (int i = 0; i < b.data.size(); i++) {
        if (p2->val > 0 || lenB == 1) break;
        p2 = p2->next;
        q = q->next;
        lenB--;
    }
    //商最多有lenA-lenB+1位
    for (int i = 0; i < lenA - lenB + 1; i++)
        quo.data.push_back(0);
    auto baseA = p1, baseB = p2;
    auto baseC = p, baseD = quo.data.head->next;
    //p1 被除数的第一个位置
    //p2 除数的第一个位置
    //p 余数的第一个位置
    //q 商的第一个位置
//    for (int i = 0; i < quo.data.size(); i++) {
//        //能不能减
//        while (true) {
//            int flag = 0;
//            if (false) flag = 1;
//            else {
//                auto pd = baseD, pb = baseB;
//                for (int j = 0; j < i; j++) pd = pd->next;
//                for (int j = 0; j < lenB; j++) {
//                    if (pd->val > pb->val) {
//                        flag = 1;
//                        break;
//                    }
//                    if (pd->val < pb->val) {
//                        flag = -1;
//                        break;
//                    }
//                    pb = pb->next;
//                    pd = pd->next;
//                }
//            }
//            if (flag != -1) {
//                auto pb = baseB, pd = baseD;
//                for (int j = 0; j < lenB; j++) {
//                    pb = pb->next;
//                    pd = pd->next;
//                }
//                for (int j = 0; j < lenB; j++) {
//                    pd->val -= pb->val;
//                    if (pd->val < 0) {
//                        pd->val += 10;
//                        pd->prev->val--;
//                    }
//                    pb = pb->prev, pd = pd->prev;
//                }
//                baseC->val++;
//            } else break;
//        }
//        baseC = baseC->next;
//        baseD = baseD->next;
//    }
    for (int i = 0; i < lenA - lenB; i++)
        tmp.data.push_back(0);
    tmp.data.display();
    for (int i = 0; i < rem.data.size(); i++) {
        while (true) {
            int flag = 0;
            auto pa = q,
                    pb = baseD;
            for (int j = 0; j < lenA - i + 1; j++) {
                if (pa->val > pb->val) {
                    flag = -1;
                    break;
                }
                if (pa->val < pb->val) {
                    flag = 1;
                    break;
                }
                pa = pa->next;
                pb = pb->next;
            }
            if (flag == -1) break;
            rem = sub(rem, tmp).second;
            rem.data.display();
            baseC->val++;
        }
        tmp.data.pop_back();
        baseC = baseC->next;
        baseD = baseD->next;
    }
    return {quo, rem};
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

void BigInteger::displayAll() {
    data.displayAll();
}

#endif //BIGINTEGER_FOR_DATA_STRUCTURE_BIGINTEGER_CPP
