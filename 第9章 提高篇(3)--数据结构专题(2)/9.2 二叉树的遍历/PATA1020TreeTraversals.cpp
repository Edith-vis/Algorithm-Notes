#include <iostream>
#include <queue>
using namespace std;

#define maxn 101
int post[maxn];
int in[maxn];
int n;

struct node{
    int data;
    node* left;
    node* right;
    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

node* create(int postL, int postR, int inL, int inR) {
    if (postL > postR) return NULL;
    
    node * root = new node(post[postR]);

    int k;
    for (k = inL; k <= inR; k++) {
        if (post[postR] == in[k]) {
            break;
        }
    }
    int lengthLeft = k - inL;
    root->left  = create(postL, postL + lengthLeft - 1, inL, k-1);
    root->right = create(postL+lengthLeft, postR-1, k+1, inR);
    return root;
}


int num = 0;
void BFS(node * root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node * now = q.front();
        q.pop();
        printf("%d", now->data);
        num++;
        if (num < n) printf(" ");
        if (now->left) q.push(now->left);
        if (now->right) q.push(now->right);
    }
}



int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    node * root = create(0, n-1, 0, n-1);
    BFS(root);

    return 0;
}