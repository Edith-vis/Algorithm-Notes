#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Node {
    int address, key, next;
    bool flag;
} node[maxn];

bool cmp (Node a, Node b) {
    if (a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    } else {
        return a.key < b.key;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    for (int i = 0; i < maxn; i++) {
        node[i].key = maxn;
        node[i].flag = false;
    }
    int n, begin;
    scanf("%d %d", &n, &begin);

    int address;
    for (int i = 0; i < n; i++) {
        scanf("%d ", &address);
        scanf("%d %d", &node[address].key, &node[address].next);
        node[address].address = address;
    }

    int cnt = 0; 
    int p = begin;
    while (p != -1) {
        node[p].flag = true;
        cnt++;
        p = node[p].next;
    }

    if (cnt == 0) {
        printf("0 -1\n");
        return 0;
    }

    sort(node, node+maxn, cmp);

    printf("%d %05d\n", cnt, node[0].address);
    for (int i = 0; i < cnt; i++) {
        if (i != cnt - 1) {
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
        } else {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
        
    }

    return 0;
}