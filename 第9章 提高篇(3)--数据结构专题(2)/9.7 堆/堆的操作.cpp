#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 101

int heap[maxn], n = 10;

//从下往上调整
void downAdjust(int low, int high) {
    int i = low, j = i * 2;

    while (j <= high) {
        if (j + 1 <= high && heap[j+1] > heap[j]) {
            j = j + 1;
        }

        if (heap[i] < heap[j]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

//建堆
void createHeap() {
    for (int i = n/2; i >= 1; i--) {
        downAdjust(i, n);
    }
}

//删除堆顶元素
void deleteTop() {
    heap[1] = heap[n--];
    downAdjust(1, n);
}

//向上调整
void upAdjust(int low, int high) {
    int i = high, j = i/2;

    while (j >= low) {
        if (heap[j] < heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i/2;
        } else {
            break;
        }
    }
}

void insert(int x) {
    heap[++n] = x;
    upAdjust(1, n);
}

//堆排序：由小到大排序
void heapSort() {
    createHeap();
    for (int i = n; i >= 1; i--) {
        swap(heap[1], heap[i]);
        downAdjust(1, i-1);
    }
}