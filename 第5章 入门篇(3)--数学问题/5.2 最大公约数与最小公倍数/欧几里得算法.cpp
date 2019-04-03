#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a/gcd(a,b)*b;
}

int main() {

}