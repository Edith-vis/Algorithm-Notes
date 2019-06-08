#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;

int n;
double p, r;

struct node {
    vector<int> child;
}Node[maxn];

int maxDepth = -1, num_max = 0;
void DFS(int id, int depth) {
    if (Node[id].child.size() == 0) {
        if (depth == maxDepth) num_max++;
        else if (depth > maxDepth) {
            maxDepth = depth;
            num_max = 1;
        }
        return;
    }

    for (int i = 0; i < Node[id].child.size(); i++) {
        DFS(Node[id].child[i], depth + 1);
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%lf%lf", &n, &p, &r);
    r = r / 100.0;

    int root;
    for (int i = 0; i < n; i++) {
        int father;
        scanf("%d", &father);
        if (father == -1) root = i;
        else {
            Node[father].child.push_back(i);
        }
    }

    DFS(root, 0);
    printf("%.2lf %d\n", p*pow(1+r, maxDepth), num_max);
    

    return 0;
}