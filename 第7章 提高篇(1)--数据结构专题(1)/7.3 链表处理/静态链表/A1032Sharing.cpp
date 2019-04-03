#include <iostream>
using namespace std;

struct Node
{
    char data;
    int next;
    bool flag;//true则表示在第一条链表里出现过
}node[100010];

int main() {
    freopen("D:/in.txt", "r", stdin);

    for (int i = 0; i < 100010; i++) {
        node[i].flag = false;
    }

    int head1, head2, cnt;
    scanf("%d %d %d", &head1, &head2, &cnt);
    for (int i = 0; i < cnt; i++) {
        int address, data, next;
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }

    //遍历第一条
    for (int i = head1; i != -1; i = node[i].next) {
        node[i].flag = true;
    }

    //遍历第二条
    for (int i = head2; i != -1; i = node[i].next) {
        if (node[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}