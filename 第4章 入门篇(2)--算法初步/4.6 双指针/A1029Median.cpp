#include <iostream>
using namespace std;

int n, m;

#define maxn 200010
int a[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }


    scanf("%d", &m);
    int mid = (n + m + 1) / 2;
    int cnt = 0, i = 0;

    for (int j = 0; j < m; j++) {
        int temp;
        scanf("%d", &temp);
        
        while (a[i] < temp && i < n) {
            cnt++;
            if (cnt == mid) {
                printf("%d", a[i]);
                return 0;
            }
            i++;
        } 
        
        cnt++;
        if (cnt == mid) {
            printf("%d", temp);
            return 0;
        }
    }

    while (i < n) {
        cnt++;
        if (cnt == mid) {
            printf("%d", a[i]);
            return 0;
        }
        i++;
    }

    return 0;
}