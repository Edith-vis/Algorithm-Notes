#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int n;

int CBT[maxn], number[maxn], index = 0;

void inOrder(int root) {
    if (root > n) return;
    inOrder(root*2);//左子树
    CBT[root] = number[index++];
    inOrder(root*2+1);//右子树
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }
    sort(number, number+n);
    inOrder(1);//根节点是1
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", CBT[i]);
    }

    return 0;
}