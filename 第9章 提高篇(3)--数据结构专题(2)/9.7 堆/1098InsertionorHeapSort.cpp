#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 111;
int origin[maxn], tempOri[maxn], changed[maxn];

int n;
bool isSame(int A[], int B[]) {
    for (int i = 1; i <= n; i++) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

void showArray(int A[]) {
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

bool insertSort() {
    bool flag = false;
    for (int i = 2; i <= n; i++) {
        if (i != 2 && isSame(tempOri, changed)){
            flag = true;
        }   

        sort(tempOri + 1, tempOri + 1 + i);

        if (flag == true) return true;
    }
    return false;
}

void downAdjust(int low, int high) {
    int i = low, j = 2*i;
    while (j <= high) {
        if (j+1 <= high && tempOri[j+1] > tempOri[j]) {
            j = j+1;
        }
        if (tempOri[i] < tempOri[j]) {
            swap(tempOri[i], tempOri[j]);
            i = j;
            j = 2*i;
        } else {
            break;
        }
    }
}

void heapSort() {
    bool flag = false;
    for (int i = n/2; i >= 1; i--) {
        downAdjust(i, n);
    }

    for (int i = n; i > 1; i--) {
        if (i != n && isSame(tempOri, changed)) {
            flag = true;
        }

        swap(tempOri[i], tempOri[1]);
        downAdjust(1, i-1);
        if (flag == true) {
            showArray(tempOri);
            return;
        }
    }
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &origin[i]);
        tempOri[i] = origin[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &changed[i]);
    }
    if (insertSort() == true) {
        printf("Insertion Sort\n");
        showArray(tempOri);
    } else {
        for (int i = 1; i <= n; i++) {
            tempOri[i] = origin[i];
        }
        printf("Heap Sort\n");
        heapSort();
    }
    return 0;
}