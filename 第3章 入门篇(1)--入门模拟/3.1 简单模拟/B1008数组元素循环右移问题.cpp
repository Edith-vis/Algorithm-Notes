#include <iostream>
using namespace std;

#define maxn 101
int a[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < m; i++) {
        int temp = a[n-1];
        for (int j = n-1; j > 0; j--) {
            a[j] = a[j-1];
        }
        a[0] = temp;
    }

    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}