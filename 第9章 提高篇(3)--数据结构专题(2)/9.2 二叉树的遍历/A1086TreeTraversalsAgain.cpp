#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int maxn = 50;

struct node {
    int data;
    node* left;
    node* right;
    node (int _data) {
        data = _data;
        left = NULL;
        right = NULL;
    } 
};

int n, in[maxn], pre[maxn];

node* create(int inL, int inR, int preL, int preR) {
    if (preR < preL) return NULL;

    node* root = new node(pre[preL]);

    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == pre[preL]) break;
    }

    int numLeft = k - inL;
    root->left = create(inL, k-1, preL + 1, preL + numLeft);
    root->right = create(k+1, inR, preL + numLeft + 1, preR);
    return root;
}

int num = 0;
void postorder(node* root) {
    if (root == NULL) return;
    if (root->left != NULL) postorder(root->left);
    if (root->right != NULL) postorder(root->right);
    if (num != 0) printf(" ");
    num++;
    printf("%d", root->data);
};



int main() {
    //freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    stack<int> st;

    int x, preIndex = 0, inIndex = 0;
    char str[5];
    for (int i = 0; i < 2 * n; i++) {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0) {
            scanf("%d", &x);
            pre[preIndex++] = x;
            st.push(x);
        } else {
            in[inIndex++] = st.top();
            st.pop();
        }
    }

    // for (int i = 0; i < n; i++) {
    //     printf("%d ", in[i]);
    // }

    node* root = create(0, n-1, 0, n-1);
    //printf("%d\n", root->data);
    postorder(root);

    return 0;
}