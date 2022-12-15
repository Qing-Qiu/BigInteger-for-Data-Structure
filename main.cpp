#include "BigInteger.h"
#include <ctime>
#include <fstream>

using namespace std;

int main() {
    while (true) {
        cout << "Please select your input method:\npress 1: keyboard\notherwise: file\n";
        string io;
        getline(cin, io);
        cout << "Please enter the operation method you select:\n1.addition\n2.subtraction\n3.multiplication\n"
                "4.division\n5.exponentiation\n0.EXIT\n";
        string opt;
        getline(cin, opt);
        if (opt == "1") {
            string s, t;
            if (io == "1") {
                cout << "Please type in two big integers in two lines:\n";
                getline(cin, s);
                getline(cin, t);
            } else {
                ifstream in("../in.txt");
                getline(in, s);
                getline(in, t);
            }
            BigInteger a(s), b(t);
            clock_t startTime = clock();
            BigInteger res = BigInteger::add(a, b);
            clock_t endTime = clock();
            res.displayLen(io);
            if (io == "1")
                res.display();
            else res.fileDisplay();
            cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
        } else if (opt == "2") {
            string s, t;
            if (io == "1") {
                cout << "Please type in two big integers in two lines:\n";
                getline(cin, s);
                getline(cin, t);
            } else {
                ifstream in("../in.txt");
                getline(in, s);
                getline(in, t);
            }
            BigInteger a(s), b(t);
            clock_t startTime = clock();
            auto res = BigInteger::sub(a, b);
            clock_t endTime = clock();
            if (res.first == '-') {
                if (io == "1") cout << '-';
                else {
                    ofstream out("../out.txt");
                    out << '-';
                }
            }
            res.second.displayLen(io);
            if (io == "1")
                res.second.display();
            else res.second.fileDisplay();
            cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
        } else if (opt == "3") {
            string s, t;
            if (io == "1") {
                cout << "Please type in two big integers in two lines:\n";
                getline(cin, s);
                getline(cin, t);
            } else {
                ifstream in("../in.txt");
                getline(in, s);
                getline(in, t);
            }
            BigInteger a(s), b(t);
            clock_t startTime = clock();
            BigInteger res = BigInteger::mul(a, b);
            clock_t endTime = clock();
            if (io == "1")
                res.display();
            else res.fileDisplay();
            cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
        } else if (opt == "4") {
            string s, t;
            if (io == "1") {
                cout << "Please type in two big integers in two lines:\n";
                getline(cin, s);
                getline(cin, t);
            } else {
                ifstream in("../in.txt");
                getline(in, s);
                getline(in, t);
            }
            BigInteger a(s), b(t);
            if (BigInteger::isZero(b)) {
                cerr << "Error: Divide by 0\n";
                continue;
            } else {
                clock_t startTime = clock();
                pair<BigInteger, BigInteger> res = BigInteger::div(a, b);
                clock_t endTime = clock();
                if (io == "1")
                    res.first.display(), res.second.display();
                else res.first.fileDisplay(), res.second.fileDisplay();
                cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
            }
        } else if (opt == "5") {
            string s, t;
            if (io == "1") {
                cout << "Please type in two big integers in two lines:\n";
                getline(cin, s);
                getline(cin, t);
            } else {
                ifstream in("../in.txt");
                getline(in, s);
                getline(in, t);
            }
            BigInteger a(s), b(t);
            if (BigInteger::isZero(a) && BigInteger::isZero(b)) {
                cerr << "Error: 0 ^ 0 undefined\n";
                continue;
            } else {
                clock_t startTime = clock();
                BigInteger res = BigInteger::exp(a, b);
                clock_t endTime = clock();
                cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
                if (io == "1")
                    res.display();
                else res.fileDisplay();
            }
        } else if (opt == "0") {
            break;
        } else {
            cout << "请重新输入!\n";
        }
    }
    return 0;
}