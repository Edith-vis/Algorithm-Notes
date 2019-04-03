#include <iostream>
#include <queue>
using namespace std;

#define maxn 101
int n, m;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};

struct Node{
    int x, y;
}node;

int add[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
};

bool judge(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (matrix[x][y] == 0 || inq[x][y] == true) return false;
    return true;
}

void BFS(int x, int y) {
    queue<Node> q;
    node.x = x;
    node.y = y;
    q.push(node);
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            node.x = top.x+add[i][0];
            node.y = top.y+add[i][1];
            if (judge(node.x, node.y)) {
                q.push(node);
                inq[node.x][node.y] = true;
            }
        }
    }

}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (judge(i, j)) {
                cnt++;
                BFS(i, j);//做标记
            }
        }
    }
    printf("%d", cnt);
    return 0;
}