#include <iostream>
#include <cstring>
using namespace std;

#define maxn 10001

int a[maxn];
int hashTable[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    memset(hashTable, 0, sizeof(hashTable));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        hashTable[a[i]]++;
    }

    int i;
    for (i = 0; i < n; i++) {
        if (hashTable[a[i]] == 1) {
            printf("%d", a[i]);
            break;
        }
    }

    if (i == n) {
        printf("None");
    }




    return 0;
}