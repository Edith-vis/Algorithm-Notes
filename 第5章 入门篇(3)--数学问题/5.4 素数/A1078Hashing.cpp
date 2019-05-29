#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

#define maxn 100010
bool hashtable[maxn] = {false};//false表示未被使用

int main() {
    freopen("D:/in.txt", "r", stdin);
    int TSize, n;
    scanf("%d %d", &TSize, &n);
    while (isPrime(TSize) == false) {
        TSize++;
    }

    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        int h = temp % TSize;
        if (hashtable[h] == false) {
            if (i != 0) printf(" ");
            printf("%d", h);
            hashtable[h] = true;
        } else {
            int step;
            for (step = 1; step < TSize; step++) {
                h = (temp + step*step) % TSize;
                if (hashtable[h] == false) {
                    if (i != 0) printf(" ");
                    printf("%d", h);
                    hashtable[h] = true;
                    break;
                }
            }
            if (step >= TSize) {
                if (i != 0) printf(" ");
                printf("-");
            }

        }
    }

    return 0;
}