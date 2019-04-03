#include <iostream>
#include <algorithm>
using namespace std;

int A[4];

void to_array(int n, int num[]) {
    int i = 0;
    do{
        num[i++] = n%10;
        n/=10;
    } while (n!=0);
}

bool cmp(int a, int b) {
    return a>b;
}

int to_number(int num[]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum = sum*10+num[i];
    }
    return sum;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, Max, Min;
    scanf("%d", &n);
    int num[5];
    while(1) {
        to_array(n, num);
        sort(num, num+4);
        Min = to_number(num);
        sort(num, num+4, cmp);
        Max = to_number(num);
        n = Max - Min;
        printf("%04d-%04d=%04d\n", Max, Min, n);
        if (n == 0 || n == 6174) break;
    }
    return 0;
}