#include <iostream>
#include <queue>
using namespace std;

#define maxn 101
int n, m;
char maze[maxn][maxn];
bool inq[maxn][maxn] = {false};

struct Node{
    int x, y;
    int step;
} S, T, node;

bool judge(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (maze[x][y] == '*' || inq[x][y] == true) return false;
    return true;
}

int add[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

int BFS() {
    queue<Node> q;
    q.push(S);
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        if (top.x == T.x && top.y == T.y) return top.step;
        for (int i = 0; i < 4; i++) {
            node.x = top.x + add[i][0];
            node.y = top.y + add[i][1];
            node.step = top.step+1;
            if (judge(node.x, node.y)) {
                q.push(node);
                inq[node.x][node.y] = true;
            }
        }
    }

    return -1;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            scanf("%c", &maze[i][j]);
            //printf("%c", maze[i][j]);
        }
    }
    scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
    S.step = 0;
    printf("%d", BFS());
    return 0;
}