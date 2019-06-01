#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Node {
    int address, data, next;
    int order;
} node[maxn];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    freopen("D:/in.txt", "r", stdin);

    for (int i = 0; i < maxn; i++) {
        node[i].order = maxn;
    }

    int begin, n, k;
    scanf("%d%d%d", &begin, &n, &k);

    int address;
    for (int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }

    //遍历链表 去除无用 标记order
    int p = begin;
    int cnt = 0;
    while (p != -1) {
        node[p].order = cnt++;
        p = node[p].next;
    }

    sort(node, node + maxn, cmp);
    n = cnt;//接下来只输出有用的结点

    //对每一节
    for (int i = 0; i < n/k; i++) {
        //每一节的后k-1个结点
        int j;
        for (j = i*k + k-1; j > i*k + 0; j--) {
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j-1].address);
        }
        printf("%05d %d ", node[j].address, node[j].data);

        if (i < n/k - 1) {
            printf("%05d\n", node[(i+1)*k+k-1].address);
        } else {
            if (n % k == 0) {
                printf("-1\n");
            } else {
                printf("%05d\n", node[(i+1)*k].address);
                for (int j = (i + 1) * k; j < n; j++) {
                    printf("%05d %d ", node[j].address, node[j].data);
                    if (j != n - 1) {
                        printf("%05d\n", node[j+1].address);
                    } else {
                        printf("-1\n");
                    }
                }
            }
        }
    }

    return 0;
}