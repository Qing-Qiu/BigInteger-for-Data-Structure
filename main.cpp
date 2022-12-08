#include "List.h"
#include "BigInteger.h"
#include<time.h>

using namespace std;

int main() {
    clock_t startTime = clock();
    /*
     *
     */
    clock_t endTime = clock();
    cout << "Running time: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms\n";
    return 0;
}