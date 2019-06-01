#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100010;

bool isExist[10010];

struct Node {
    int address, key, next;
    int order;
} node[maxn];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    freopen("D:/in.txt", "r", stdin);

    memset(isExist, false, sizeof(isExist));

    for (int i = 0; i < maxn; i++) {
        node[i].order = 2 * maxn;
    }

    int begin, n;
    scanf("%d %d", &begin, &n);

    int address;
    for (int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d %d", &node[address].key, &node[address].next);
        node[address].address = address;
    }

    int val_cnt = 0, inval_cnt = 0;
    int p = begin;
    while (p != -1) {
        if (isExist[abs(node[p].key)] == false) {
            isExist[abs(node[p].key)] = true;
            node[p].order = val_cnt++;
        } else {
            node[p].order = maxn + inval_cnt++;
        }

        p = node[p].next;
    }

    sort(node, node + maxn, cmp);
    int cnt = val_cnt + inval_cnt;
    for (int i = 0; i < cnt; i++) {
        if (i != val_cnt - 1 && i != val_cnt + inval_cnt - 1) {
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
        } else {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
    }

    return 0;
}