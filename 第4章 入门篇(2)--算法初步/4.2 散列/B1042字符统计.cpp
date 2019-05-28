#include <iostream>
#include <cstring>
using namespace std;

#define maxn 1001
char input[maxn];

int hashtable[26] = {0};

int main() {
    freopen("D:/in.txt", "r", stdin);
    cin.getline(input, maxn);
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            hashtable[input[i]-'a']++;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            hashtable[input[i]-'A']++;
        }
    }

    int id = -1, maxTimes = -1;
    for (int i = 0; i < 26; i++) {
        if (hashtable[i] > maxTimes) {
            maxTimes = hashtable[i];
            id = i;
        }
    }

    printf("%c %d", id+'a', maxTimes);

    return 0;
}