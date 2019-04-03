#include <iostream>
using namespace std;

#define maxn 101
int a[maxn];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int i = 0, j = n-1;
    while (i < j) {
        if (a[i]+a[j] == m) {
            printf("%d %d\n", i, j);
            i++;
            j--;
        } else if (a[i]+a[j] < m) {
            i++;
        } else {
            j--;
        }
    }
    return 0;
}

//序列合并问题
int merge(int A[], int B[], int C[], int n, int m) {
    int i = 0, j = 0;
    int index = 0;
    while (i < n && j < m) {
        if (A[i] <= B[i]) {
            C[index++] = A[i++];
        } else {
            C[index++] = B[j++];
        }
    }

    while (i < n) C[index++] = A[i++];
    while (j < m) C[index++] = B[j++];
    return index;
}