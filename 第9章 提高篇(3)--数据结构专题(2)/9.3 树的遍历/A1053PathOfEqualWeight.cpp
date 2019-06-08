#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define maxn 101

struct Node{
    int weight;
    vector<int> child;
}node[maxn];

int n, m, S;//结点数，非叶子结点数，目标权值

vector<int> path;

void DFS(int index, int sum) {
    if (sum > S) return;
    if (sum == S) {
        if (!node[index].child.empty()) return;

        for (int i = 0; i < path.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", node[path[i]].weight);
            if (i == path.size()-1) printf("\n");
        }
        return;
    }

    for (int i = 0; i < node[index].child.size(); i++) {
        int child = node[index].child[i];
        path.push_back(child);
        DFS(child, sum + node[child].weight);
        path.pop_back();
    }
}

int cmp(int a, int b) {
    return node[a].weight > node[b].weight;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &S);

    for (int i = 0; i < n; i++) {
        scanf("%d", &node[i].weight);
    }

    int id, k, childid;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &childid);
            node[i].child.push_back(childid);
        }
        sort(node[i].child.begin(), node[i].child.end(), cmp);
    }

    path.push_back(0);
    DFS(0, node[0].weight);

    return 0;
}