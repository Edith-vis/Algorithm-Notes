#include <iostream>
using namespace std;

int array[32], aNum = 0;

bool isPrime(int x) {
    if (x <= 1) return false;
    
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

void convertToD(int n, int d) {
    aNum = 0;
    do {
        array[aNum++] = n % d;
        n /= d; 
    } while (n != 0);
}

int convertToTen(int d) {
    int ans = 0;
    for (int i = 0; i < aNum; i++) {
        ans = ans * d + array[i];
    }
    return ans;
}
int main() {
    freopen("D:/in.txt", "r", stdin);

    int n, d;
    while (scanf("%d %d", &n, &d) && n > 0) {
        convertToD(n, d);
        if (isPrime(n) && isPrime(convertToTen(d))) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}