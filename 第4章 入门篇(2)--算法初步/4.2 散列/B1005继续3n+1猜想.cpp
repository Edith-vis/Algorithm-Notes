#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, a[101];
    scanf("%d", &n);

    bool hashTable[1000] = {false};

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        int m = a[i];
        while (m != 1) {
            if (m%2 == 1) {
                m = (3*m+1)/2;
            } else {
                m = m/2;
            }
            hashTable[m] = true;
        }
    }

    sort(a, a+n, cmp);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (hashTable[a[i]] == false) {
            cnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (hashTable[a[i]] == false) {
            printf("%d", a[i]);
            cnt--;
            if (cnt != 0) printf(" ");
        }
    }

    return 0;
}