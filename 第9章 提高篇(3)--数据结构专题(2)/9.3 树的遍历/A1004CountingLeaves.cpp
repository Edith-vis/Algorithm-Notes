#include <iostream>
#include <vector>
using namespace std;

const int maxn = 110;
int n, m;

vector<int> Node[maxn];

int hashTable[maxn] = {0};
int maxLevel = -1;
void DFS(int index, int level) {
    if (Node[index].size() == 0) {
        if (level > maxLevel) maxLevel = level;
        hashTable[level]++;
        return;
    }

    for (int i = 0; i < Node[index].size(); i++) {
        DFS(Node[index][i], level+1);
    }
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &m);

    int father, child, k;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &father, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            Node[father].push_back(child);
        }
    }

    int root = 01;
    DFS(root, 0);
    for (int i = 0; i <= maxLevel; i++) {
        if (i != 0) printf(" ");
        printf("%d", hashTable[i]);
    }

    return 0;
}