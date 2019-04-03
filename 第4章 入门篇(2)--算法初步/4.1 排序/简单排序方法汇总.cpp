#include <cstdio>
#define maxn 100001

int A[maxn], n;//编号从1-n

void selectSort() {
    for (int i = 1; i <= n; i++) {
        int k = i;
        for (int j = i+1; j <= n; j++) {
            if (A[j] < A[k]) {
                k = j;
            }
        }
        int temp = A[k];
        A[k] = A[i];
        A[i] = temp;
    }
}

void insertSort() {
    for (int i = 2; i <= n; i++) {
        int temp = A[i], j = i;
        while (j > 1 && temp < A[j-1]) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = temp;
    }
}

void bubbleSort() {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main() {

    return 0;
}