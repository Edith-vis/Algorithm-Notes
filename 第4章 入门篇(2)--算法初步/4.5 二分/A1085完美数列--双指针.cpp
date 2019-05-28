#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 100010

long long input[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &input[i]);
    }
    sort(input, input + n);

    int i = 0, j = 0, max_num = 0;
    while (i < n && j < n) {
        long long temp = input[i]*p;
        if (temp < input[j]) {
            i++;
        } else {
            if (j - i > max_num) {
                max_num = j - i;
            }
        }
        j++;
        //printf("%d %d\n", i, j);
    }
    printf("%d", j-i);

    return 0;
}