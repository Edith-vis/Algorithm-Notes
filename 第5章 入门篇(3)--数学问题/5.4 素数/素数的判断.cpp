#include <iostream>
#include <cmath>
using namespace std;

bool isPrime1(int num) {
    if (num <= 1) return false;
    int sqr = (int)sqrt(1.0*num);
    for (int i = 2; i <= sqr; i++) {
        if (num%i == 0) return false;
    }
    return true;
}

bool isPrime2(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i <= num; i++) {
        if (num%i==0) return false;
    }
    return true;
}

int main() {

    return 0;
}