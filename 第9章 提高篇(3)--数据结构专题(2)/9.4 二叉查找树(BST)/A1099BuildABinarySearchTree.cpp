#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 110;
int n, in[maxn], index = 0;

struct node {
    int data;
    int left, right;
} Node[maxn];

void inOrder(int root) {
    if (root == -1) return;

    inOrder(Node[root].left);
    Node[root].data = in[index++];
    inOrder(Node[root].right);
}


void BFS(int root) {
    index = 0;
    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int front = q.front();
        if (index != 0) printf(" ");
        printf("%d", Node[front].data);
        index++;
        q.pop();
        if (Node[front].left != -1) q.push(Node[front].left);
        if (Node[front].right != -1) q.push(Node[front].right);
    }
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &Node[i].left, &Node[i].right);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    sort(in, in + n);
    inOrder(0);
    BFS(0);

    return 0;
}