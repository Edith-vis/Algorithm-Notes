#include <iostream>
#include <cstring>
using namespace std;

int hashTable1[10] = {0};
int hashTable2[10] = {0};

int main() {
    freopen("D:/in.txt", "r", stdin);
    char input[30];
    scanf("%s", input);

    int output[30];

    for (int i = 0; i < strlen(input); i++) {
        hashTable1[input[i]-'0']++;
    }

    int r = 0;
    int num = 0;
    for (int i = strlen(input)-1; i >= 0; i--) {
        output[num++] = (r + (input[i]-'0')*2) % 10;
        hashTable2[(r + (input[i]-'0')*2) % 10] ++;
        r = (r + (input[i]-'0')*2) / 10;
    }
    if (r != 0) output[num++] = r;

    if (num != strlen(input)) {
        printf("No\n");
    } else {
        int i;
        for (i = 0; i < 10; i++) {
            if (hashTable1[i] != hashTable2[i]) {
                printf("No\n");
                break;
            }
        }
        if (i >= 10) printf("Yes\n");
    }

    for (int i = num-1; i >= 0; i--) {
        printf("%d", output[i]);
    }



    return 0;
}