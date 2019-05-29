#include <iostream>
#include <cmath>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    long long num;
    scanf("%lld", &num);
    
    long long sqr = (long long) sqrt(1.0*num);
    long long ansLen = 0, ansI = 0;
    for (int i = 2; i <= sqr; i++) {
        long long temp_multi = 1, j = i;
        while (1) {
            temp_multi *= j;
            if (num % temp_multi != 0) {
                break;
            }
            if (j - i + 1 > ansLen) {
                ansLen = j - i + 1;
                ansI = i;
            }
            j++;
        }
    }

    if (ansLen == 0) {
        printf("1\n");
        printf("%lld", num);
    } else {
        printf("%lld\n", ansLen);
        for (long long i = ansI; i < ansI + ansLen; i++) {
            if (i != ansI) printf("*");
            printf("%lld", i);
        }
    }

    return 0;
}