#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int partition(int A[], int left, int right) {
    //int p = round(1.0*rand()/RAND_MAX*(right-left)+left);
    int temp = A[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && A[j] > temp) j--;
        A[i] = A[j];
        while (i < j && A[i] <= temp) i++;
        A[j] = A[i];
    }
    A[i] = temp;
    return i;
}

void quickSort(int A[], int left, int right) {
    if (left < right) {
        int pos = partition(A, left, right);
        quickSort(A, left, pos-1);
        quickSort(A, pos+1, right);
    }
}

int main() {

}