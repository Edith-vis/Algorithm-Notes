#include <iostream>
#include <cstring>
using namespace std;

bool hashTable[128];

#define maxn 10001

int main() {
    freopen("D:/in.txt", "r", stdin);
    memset(hashTable, false, sizeof(hashTable));

    char str1[maxn], str2[maxn];
    cin.getline(str1, maxn);
    cin.getline(str2, maxn);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i < len2; i++) {
        hashTable[str2[i]] = true;
    }

    for (int i = 0; i < len1; i++) {
        if (hashTable[str1[i]] == true) continue;
        else printf("%c", str1[i]);
    }

    return 0;
}