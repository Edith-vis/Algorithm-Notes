#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 100001

char str[maxn];

bool HashTable[256];

int main() {
    freopen("D:/in.txt", "r", stdin);

    memset(HashTable, true, sizeof(HashTable));//初始化为每个键都可用

    cin.getline(str, maxn);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i]-'A'+'a';
        HashTable[str[i]] = false;
    }

    cin.getline(str, maxn);
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            if (HashTable[str[i]-'A'+'a'] == true && HashTable['+'] == true) {
                printf("%c", str[i]);
            }
        } else if (HashTable[str[i]] == true) {
            printf("%c", str[i]);
        }
    }

    return 0;
}