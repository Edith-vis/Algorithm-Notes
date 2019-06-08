#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110;

struct node {
    int weight;
    vector<int> child;
} Node[maxn];

bool cmp(int a, int b) {
    return Node[a].weight > Node[b].weight;
}

int n, m, s;
vector<int> path;
void DFS(int index, int sum_weight) {
    if (sum_weight > s) return;
    if (sum_weight == s) {
        if (Node[index].child.size() != 0) return;
        //printf("%d", s);

        //打印路径
        for (int i = 0; i < path.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", path[i]);
        }
        printf("\n");
    }
    //printf("%d\n", index);

    for (int i = 0; i < Node[index].child.size(); i++) {
        int child = Node[index].child[i];
        path.push_back(Node[child].weight);
        DFS(child, sum_weight + Node[child].weight);
        path.pop_back();
    }
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &Node[i].weight);
    }

    int father, child, k;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &father, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            Node[father].child.push_back(child);
        }
        sort(Node[father].child.begin(), Node[father].child.end(), cmp);
    }

    path.push_back(Node[0].weight);
    DFS(0, Node[0].weight);

    return 0;
}