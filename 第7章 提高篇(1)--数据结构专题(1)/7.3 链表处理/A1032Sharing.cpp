#include <iostream>
using namespace std;

const int maxn = 100010;

struct Node {
    int address, next;
    char data;
    bool flag;
} node[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    for (int i = 0; i < maxn; i++) {
        node[i].flag = false;
    }

    int begin1, begin2, n;
    scanf("%d %d %d", &begin1, &begin2, &n);

    int address;
    for (int i = 0; i < n; i++) {
        scanf("%d ", &address);
        scanf("%c %d", &node[address].data, &node[address].next);
        node[address].address = address;
    }

    int p1 = begin1, p2 = begin2;
    while (p1 != -1) {
        node[p1].flag = true;
        p1 = node[p1].next;
        //printf("%d\n", p1);
    }

    while (p2 != -1) {
        if (node[p2].flag == true) {
            printf("%05d\n", p2);
            return 0;
        } 
        p2 = node[p2].next;
    }

    printf("-1\n");

    return 0;
}