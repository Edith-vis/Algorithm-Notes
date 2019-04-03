#include <iostream>
using namespace std;

//法一
int cal1(int n, int p) {
    int ans = 0;
    while (n) {
        ans += n/p;
        n /= p;
    }
    return ans;
}

//法二
int cal2(int n, int p) {
    if (n < p) return 0;
    else return n/p + cal2(n/p, p);
}