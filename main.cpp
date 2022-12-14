#include "BigInteger.h"
#include <ctime>
#include <fstream>

using namespace std;

void init() {
    ofstream out("../out.txt", ios::ate);
    out.close();
}

int main() {
    init();
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
                in.close();
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
                in.close();
            }
            BigInteger a(s), b(t);
            clock_t startTime = clock();
            auto res = BigInteger::sub(a, b);
            clock_t endTime = clock();
            res.second.displayLen(io);
            if (res.first == '-') {
                if (io == "1") cout << '-';
                else {
                    ofstream out("../out.txt", ios::app);
                    out << '-';
                    out.close();
                }
            }
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
                in.close();
            }
            BigInteger a(s), b(t);
            clock_t startTime = clock();
            BigInteger res = BigInteger::exmul(a, b);
            clock_t endTime = clock();
            res.displayLen(io);
            if (io == "1")
                res.display();
            else res.fileDisplay();
            cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
            startTime = clock();
            res = BigInteger::mul(a, b);
            endTime = clock();
            res.displayLen(io);
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
                in.close();
            }
            BigInteger a(s), b(t);
            if (BigInteger::isZero(b)) {
                cerr << "Error: Divide by 0\n";
                continue;
            } else {
                clock_t startTime = clock();
                pair<BigInteger, BigInteger> res = BigInteger::div(a, b);
                clock_t endTime = clock();
                res.first.displayLen(io);
                if (io == "1")
                    res.first.display();
                else res.first.fileDisplay();
                res.second.displayLen(io);
                if (io == "1")
                    res.second.display();
                else res.second.fileDisplay();
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
                in.close();
            }
            BigInteger a(s), b(t), c(s), d(t);
            if (BigInteger::isZero(a) && BigInteger::isZero(b)) {
                cerr << "Error: 0 ^ 0 undefined\n";
                continue;
            } else {
                clock_t startTime = clock();
                BigInteger res = BigInteger::exexp(a, b);
                clock_t endTime = clock();
                cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
                res.displayLen(io);
                if (io == "1")
                    res.display();
                else res.fileDisplay();
                startTime = clock();
                res = BigInteger::exp(c, d);
                endTime = clock();
                cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
                res.displayLen(io);
                if (io == "1")
                    res.display();
                else res.fileDisplay();
            }
        } else if (opt == "0") {
            break;
        } else {
            cout << "???????????????!\n";
        }
    }
    return 0;
}