#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 100010
int a[maxn];

int n, m;

int binarySearch(int i, int x) {
    int left = i;
    int right = n - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    freopen("D:/in.txt", "r", stdin);


    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    //printf("%d %d\n", n, m);

    sort(a, a+n);

    for (int i = 0; i < n; i++) {
        int j = binarySearch(i, m-a[i]);
        //printf("%d - %d \n", i, j);
        if (j != -1 && j != i) {
            printf("%d %d\n", a[i], a[j]);
            return 0;
        }
    }


    printf("No Solution\n");
    

    return 0;
}