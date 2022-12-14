#include "BigInteger.h"
#include <ctime>

using namespace std;

int main() {
    while (true) {
        cout << "Please enter the operation method you select:\n1.addition\n2.subtraction\n3.multiplication\n"
                "4.division\n5.exponentiation\n0.EXIT\n";
        string opt;
        getline(cin, opt);
        if (opt == "1") {
            string s, t;
            cout << "Please type in two big integers in two lines:\n";
            getline(cin, s);
            getline(cin, t);
            BigInteger a(s), b(t);
            clock_t startTime = clock();
            BigInteger res = BigInteger::add(a, b);
            res.display();
            clock_t endTime = clock();
            cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
        } else if (opt == "2") {
            string s, t;
            cout << "Please type in two big integers in two lines:\n";
            getline(cin, s);
            getline(cin, t);
            BigInteger a(s), b(t);
            clock_t startTime = clock();
            auto res = BigInteger::sub(a, b);
            if (res.first == '-') cout << '-';
            res.second.display();
            clock_t endTime = clock();
            cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
        } else if (opt == "3") {
            string s, t;
            cout << "Please type in two big integers in two lines:\n";
            getline(cin, s);
            getline(cin, t);
            BigInteger a(s), b(t);
            clock_t startTime = clock();
            BigInteger res = BigInteger::mul(a, b);
            res.display();
            clock_t endTime = clock();
            cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
        } else if (opt == "4") {
            string s, t;
            cout << "Please type in two big integers in two lines:\n";
            getline(cin, s);
            getline(cin, t);
            BigInteger a(s), b(t);
            clock_t startTime = clock();
            if (BigInteger::isZero(b)) {
                cout << "Error: Divide by 0\n";
            } else {
                pair<BigInteger, BigInteger> res = BigInteger::div(a, b);
                res.first.display();
                res.second.display();
            }
            clock_t endTime = clock();
            cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
        } else if (opt == "5") {
            string s, t;
            cout << "Please type in two big integers in two lines:\n";
            getline(cin, s);
            getline(cin, t);
            BigInteger a(s), b(t);
            clock_t startTime = clock();
            if (BigInteger::isZero(a) && BigInteger::isZero(b)) {
                cout << "Error: 0 ^ 0 undefined\n";
            } else {
                BigInteger res = BigInteger::exp(a, b);
                res.display();
            }
            clock_t endTime = clock();
            cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
        } else if (opt == "0") {
            break;
        } else {
            cout << "请重新输入!\n";
        }
    }
    return 0;
}