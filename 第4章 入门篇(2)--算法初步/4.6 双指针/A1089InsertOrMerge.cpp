#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 110
int origin[maxn], temp_origin[maxn], aimed[maxn];

int n;

bool cmp(int a[], int b[]) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void showArray(int a[]) {
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
}

bool isInsert() {
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (i != 1 && cmp(aimed, temp_origin)) {
            flag = true;
        }

        int temp = temp_origin[i], j = i;
        while (j > 0 && temp_origin[j - 1] > temp) {
            temp_origin[j] = temp_origin[j - 1];
            j--;
        }
        temp_origin[j] = temp;


        if (flag == true) {
            //showArray(temp_origin);
            return true;
        }
    }
    return false;
}

void mergeSort() {
    bool flag = false;
    for (int step = 2; step/2 <= n; step *= 2) {
        if (step != 2 && cmp(temp_origin, aimed)) {
            flag = true;
        }

        for (int i = 0; i < n; i += step) {
            sort(temp_origin + i, temp_origin + min(n, i + step));
        }

        if (flag == true) {
            showArray(temp_origin);
            return;
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
        temp_origin[i] = origin[i];
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &aimed[i]);
    }

    if (isInsert()) {
        printf("Insertion Sort\n");
        showArray(temp_origin);
    } else {
        printf("Merge Sort\n");
        for (int i = 0; i < n; i++) {
            temp_origin[i] = origin[i];
        }
        mergeSort();
    }

    return 0;
}