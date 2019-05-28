#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;



int Map[256];

//'0'-'9'映射到0-9; 'a'-'z'映射到10-35
void init() {
    for (int c = '0'; c <= '9'; c++) {
        Map[c] = c -'0';
    }

    for (int c = 'a'; c <= 'z'; c++) {
        Map[c] = c - 'a' + 10;
    }
}

long long convertTo10(char a[], long long radix) {
    int len = strlen(a);
    long long ans = 0;
    for (int i = 0; i < len; i++) {
        ans = ans*radix + Map[a[i]];
    }
    return ans;
}

int findLargestDigit(char a[]) {
    int len = strlen(a);
    int _max = -1;
    for (int i = 0; i < len; i++) {
        if (Map[a[i]] > _max) {
            _max = Map[a[i]];
        }
    }
    return _max;
}

long long binarySearch(char a[], long long left, long long right, long long num) {
    long long mid;
    while (left <= right) {
        mid = (left + right)/2;
        long long _mid = convertTo10(a, mid);
        //printf("%lld %lld\n", mid, _mid);
        if (_mid == num) {
            return mid;
        } else if (_mid > num || _mid < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

char n1[20], n2[20];
int main() {
    freopen("D:/in.txt", "r", stdin);

    init();
    
    int tag, radix;
    scanf("%s %s %d %d", n1, n2, &tag, &radix);

    //n1保存已知进制的数 n2保存待匹配进制的数
    if (tag == 2) {
        char temp[20];
        strcpy(temp, n1);
        strcpy(n1, n2);
        strcpy(n2, temp);
    }

    long long _n1 = convertTo10(n1, radix);
    long long low = findLargestDigit(n2) + 1;
    long long high = max(low, _n1) + 1;
    long long ans = binarySearch(n2, low, high, _n1);

    if (ans == -1) {
        printf("Impossible\n");
    } else {
        printf("%lld\n", ans);
    }


    return 0;
}