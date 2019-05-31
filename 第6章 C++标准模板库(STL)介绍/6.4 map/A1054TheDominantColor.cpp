#include <iostream>
#include <map>
using namespace std;

map<int, int> arr;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int m, n;
    scanf("%d %d", &m, &n);
    int mid = (m * n) / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            arr[temp]++;
            if (arr[temp] > mid) {
                printf("%d", temp);
                return 0;
            }
        }
    }

    return 0;
}