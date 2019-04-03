#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

#define maxn 100010

int A[maxn], n;

int randPartition(int A[], int left, int right) {
    int p = round(1.0*rand()/RAND_MAX*(right-left)+left);
    swap(A[p], A[left]);

    int temp = A[left];
    while (left < right) {
        while (left < right && A[right] > temp) right--;
        A[left] = A[right];
        while (left < right && A[left] <= temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void randSelection(int A[], int left, int right, int K) {
    if (left == right) return;
    int pos = randPartition(A, left, right);
    int M = pos-left+1;
    if (K == M) return;
    if (K < M) {
        randSelection(A, left, pos-1, K);
    } else {
        randSelection(A, pos+1, right, K-M);
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    randSelection(A, 0, n-1, n/2);
    int summin = 0;
    for (int i = 0; i < n/2; i++) {
        summin += A[i];
    }
    printf("%d\n", sum-summin-summin);
    return 0;
}