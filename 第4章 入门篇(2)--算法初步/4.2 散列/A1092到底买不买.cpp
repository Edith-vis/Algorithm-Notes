#include <iostream>
#include <cstring>
using namespace std;

#define maxn 1001

int hashTable[64] = {0};
int miss = 0;

int getId(char c) {
    if (c >= '0' && c <= '9') return c-'0';
    else if (c >= 'a' && c <= 'z') return c-'a'+10;
    else if (c >= 'A' && c <= 'Z') return c-'A'+36;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    char whole[maxn], need[maxn];
    cin.getline(whole, maxn);
    cin.getline(need, maxn);

    int len1 = strlen(whole);
    int len2 = strlen(need);

    for (int i = 0; i < len1; i++) {
        int id = getId(whole[i]);
        hashTable[id]++;
    }

    for (int i = 0; i < len2; i++) {
        int id = getId(need[i]);
        hashTable[id]--;
        if (hashTable[id] < 0) {
            miss++;
        }
    }

    if (miss > 0) {
        printf("No %d", miss);
    } else {
        printf("Yes %d", len1-len2);
    }

    return 0;
}