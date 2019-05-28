#include <iostream>
#include <cstring>
using namespace std;

bool HashTable[128] = {false};

int main() {
    freopen("D:/in.txt", "r", stdin);
    char s1[81], s2[81];
    scanf("%s", s1);
    scanf("%s", s2);
    //printf("%s %s", s1, s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int i = 0; i < len1; i++) {
        int j;
        char c1 = s1[i];
        if (c1 >= 'a' && c1 <= 'z') c1 -= 32;
        for (j = 0; j < len2; j++) {
            char c2 = s2[j];
            if (c2 >= 'a' && c2 <= 'z') c2 -= 32;
            if (c1 == c2) break;
        }

        if (j == len2 && HashTable[c1] == false) {
            printf("%c", c1);
            HashTable[c1] = true;
        }
    }

    return 0;
}