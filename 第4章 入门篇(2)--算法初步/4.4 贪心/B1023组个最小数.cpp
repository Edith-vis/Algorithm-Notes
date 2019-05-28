#include <iostream>
using namespace std;

int count[10] = {0};

int main() {
    freopen("D:/in.txt", "r", stdin);
    for (int i = 0; i < 10; i++) {
        int tmp;
        scanf("%d", &tmp);
        count[tmp]++;
    }

    for (int i = 1; i < 10; i++) {
        if (count[i] > 0) {
            printf("%d", i);
            count[i]--;
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        while (count[i] > 0) {
            printf("%d", i);
            count[i]--;
        }
    }
    return 0;
}