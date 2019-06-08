#include <iostream>
#include <queue>
using namespace std;

const int maxn = 20;

struct node {
    int data, left, right;
} Node[maxn];

int n;
bool isNotRoot[maxn] = {false};

int charToInt(char c) {
    if (c == '-') return -1;
    else {
        isNotRoot[c-'0'] = true;
        return c-'0';
    }
}

int findRoot() {
    for (int i = 0; i < n; i++) {
        if (isNotRoot[i] == false) return i;
    }
}

//反转二叉树
void postOrder(int root) {
    if (Node[root].left != -1)  postOrder(Node[root].left);
    if (Node[root].right != -1) postOrder(Node[root].right);

    int temp = Node[root].left;
    Node[root].left = Node[root].right;
    Node[root].right = temp;
}

int num = 0;
void levelOrder(int root) {
    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int front = q.front();
        if (num != 0) printf(" ");
        printf("%d", front);
        num++;
        q.pop();
        if (Node[front].left != -1) q.push(Node[front].left);
        if (Node[front].right != -1) q.push(Node[front].right);
    }
}

void inOrder(int root) {
    if (Node[root].left != -1) inOrder(Node[root].left);

    if (num != 0) printf(" ");
    printf("%d", root);
    num++;

    if (Node[root].right != -1) inOrder(Node[root].right);
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    char left, right;
    for (int i = 0; i < n; i++) {
        scanf("%*c%c %c", &left, &right);
        Node[i].left = charToInt(left);
        Node[i].right = charToInt(right);
    }

    int root = findRoot();
    postOrder(root);
    levelOrder(root);
    printf("\n");
    num = 0;
    inOrder(root);

    return 0;
}