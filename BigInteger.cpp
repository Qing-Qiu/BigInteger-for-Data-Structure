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

BigInteger BigInteger::add(BigInteger &a, BigInteger &b) {
    BigInteger res = *new BigInteger();
    int lenA = a.data.size(), lenB = b.data.size();
    for (int i = 0; i < lenA - lenB; i++)
        b.data.push_front(0);
    for (int i = 0; i < lenB - lenA; i++)
        a.data.push_front(0);
    int carry = 0;
    auto p1 = a.data.tail->prev, p2 = b.data.tail->prev;
    for (int i = 0; i < a.data.size(); i++) {
        res.data.push_front((p1->val + p2->val + carry) % 10);
        carry = (p1->val + p2->val + carry) / 10;
        p1 = p1->prev, p2 = p2->prev;
    }
    if (carry > 0) res.data.push_front(carry);
    return res;
}

std::pair<char, BigInteger> BigInteger::sub(BigInteger &a, BigInteger &b) {
    char sgn;
    int lenA = a.data.size(), lenB = b.data.size();
    for (int i = 0; i < lenA - lenB; i++)
        b.data.push_front(0);
    for (int i = 0; i < lenB - lenA; i++)
        a.data.push_front(0);
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

int arr[300010];
int rev[300010], bit, tot;
Complex Ca[300010], Cb[300010];

BigInteger BigInteger::exmul(const BigInteger &a, const BigInteger &b) {
    BigInteger res = *new BigInteger();
    memset(arr, 0, sizeof arr);
    memset(rev, 0, sizeof rev);
    memset(Ca, 0, sizeof Ca);
    memset(Cb, 0, sizeof Cb);
    auto p1 = a.data.tail->prev;
    auto p2 = b.data.tail->prev;
    int n = 0, m = 0;
    while (p1 != a.data.head) {
        Ca[n++].x = p1->val;
        p1 = p1->prev;
    }
    while (p2 != b.data.head) {
        Cb[m++].x = p2->val;
        p2 = p2->prev;
    }
    n--, m--;
    bit = 0;
    while ((1 << bit) < n + m + 1) bit++;
    tot = 1 << bit;
    for (int i = 0; i < tot; i++)
        rev[i] = ((rev[i >> 1] >> 1)) | ((i & 1) << (bit - 1)); //????????????
    FFT(Ca, 1), FFT(Cb, 1);
    for (int i = 0; i < tot; i++) Ca[i] = Ca[i] * Cb[i];
    FFT(Ca, -1);
    int k = 0;
    for (int i = 0, t = 0; i < tot || t; i++) {
        t = t + (int) (Ca[i].x / tot + 0.5);
        arr[k++] = t % 10;
        t /= 10;
    }
    while (k > 1 && !arr[k - 1]) k--;
    for (int i = k - 1; i >= 0; i--)
        res.data.push_back(arr[i]);
    return res;
}

const double PI = acos(-1);

void BigInteger::FFT(Complex para[], int inv) {
    for (int i = 0; i < tot; i++)
        if (i < rev[i])
            std::swap(para[i], para[rev[i]]);
    for (int mid = 1; mid < tot; mid *= 2) {
        auto w1 = Complex({cos(PI / mid), inv * sin(PI / mid)});
        for (int i = 0; i < tot; i += mid * 2) {
            auto wk = Complex({1, 0});
            for (int j = 0; j < mid; j++, wk = wk * w1) {
                auto x = para[i + j], y = wk * para[i + j + mid];
                para[i + j] = x + y, para[i + j + mid] = x - y;
            }
        }
    }
}

std::pair<BigInteger, BigInteger> BigInteger::div(const BigInteger &a, const BigInteger &b) {
    BigInteger rem = *new BigInteger(a); //??????
    BigInteger tmp = *new BigInteger(b); //??????????????????
    BigInteger quo = *new BigInteger(); //???
    auto p = rem.data.head->next;
    auto q = tmp.data.head->next;
    for (int i = 0; i < a.data.size(); i++) {
        if (p->val > 0 || rem.data.size() == 1) break;
        p = p->next;
        rem.data.pop_front();
    }   //????????????????????????????????????0
    for (int i = 0; i < b.data.size(); i++) {
        if (q->val > 0 || tmp.data.size() == 1) break;
        q = q->next;
        tmp.data.pop_front();
    }   //?????????????????????0
    int d = rem.data.size() - tmp.data.size();
    for (int i = 0; i < d; i++)
        tmp.data.push_back(0);
    //?????????????????????0???????????????????????????
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
    if (quo.data.empty()) quo.data.push_back(0);
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
        b = div(b, two).first;
    }
    return res;
}

BigInteger BigInteger::exexp(BigInteger &a, BigInteger &b) {
    BigInteger res = *new BigInteger();
    res.data.push_back(1);
    while (!isZero(b)) {
        if (b.data.tail->prev->val & 1) res = exmul(res, a);
        a = exmul(a, a);
        b = div2(b);
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
