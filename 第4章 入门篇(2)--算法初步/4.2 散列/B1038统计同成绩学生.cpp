#include <iostream>
using namespace std;

int hashTable[101] = {0};

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score);
        hashTable[score]++;
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int score;
        scanf("%d", &score);
        if (i > 0) printf(" ");
        printf("%d", hashTable[score]);
    }

    return 0;
}