#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100010

struct Node{
    int address;
    int data;
    int next;
    bool flag;//true为有效结点
}node[maxn];

bool cmp(Node a, Node b) {
    if (a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    for (int i = 0; i < maxn; i++) {
        node[i].flag = false;
    }
    int n, head;
    scanf("%d%d", &n, &head);
    for (int i = 0; i < n; i++) {
        int address, data, next;
        scanf("%d%d%d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }

    int p = head, cnt = 0;
    while (p != -1) {
        cnt++;
        node[p].flag = true;
        p = node[p].next;
    }

    if (cnt == 0) {
        printf("0 -1\n");
        return 0;
    }

    sort(node, node+maxn, cmp);
    printf("%d %05d\n", cnt, node[0].address);

    for (int i = 0; i < cnt; i++) {
        if (i == cnt-1) {
            printf("%05d %d -1\n", node[i].address, node[i].data);
        } else {
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
        }
    }

    return 0;
}