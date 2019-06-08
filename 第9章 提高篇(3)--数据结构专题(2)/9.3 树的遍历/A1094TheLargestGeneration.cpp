#include <iostream>
#include <vector>
using namespace std;

const int maxn = 110;
int n, m;

vector<int> Node[maxn];
int hashTable[maxn] = {0};

void DFS(int index, int level) {
    hashTable[level]++;

    for (int i = 0; i < Node[index].size(); i++) {
        DFS(Node[index][i], level+1);
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &m);

    int father, child, k;
    for (int j = 0; j < m; j++) {
        scanf("%d%d", &father, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &child);
            Node[father].push_back(child);
        }
    }

    DFS(1, 1);
    int maxNum = -1, maxLevel = -1;
    for (int i = 1; i < n; i++) {
        if (maxNum < hashTable[i]) {
            maxNum = hashTable[i];
            maxLevel = i;
        }
    }

    printf("%d %d\n", maxNum, maxLevel);

    return 0;
}