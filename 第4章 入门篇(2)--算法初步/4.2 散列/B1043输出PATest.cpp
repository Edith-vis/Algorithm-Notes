#include <iostream>
#include <cstring>
using namespace std;

char ahh[7] = "PATest";

int hashTable[7] = {0};

#define maxn 10001

int main() {
    freopen("D:/in.txt", "r", stdin);
    char input[maxn];
    scanf("%s", input);
    int len = strlen(input);
    //printf("%s", input);

    int num = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 6; j++) {
            if (input[i] == ahh[j]) {
                hashTable[j]++;
                num++;
            }
        }
    }

    while (num > 0) {
        for (int i = 0; i < 6; i++) {
            if (hashTable[i] > 0) {
                printf("%c", ahh[i]);
                hashTable[i]--;
                num--;
            }
        }
    }


    return 0;
}