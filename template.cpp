#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int x, y, z;
}node;

int n, m, slice, T;
int pixel[1300][150][100];
bool inq[1300][150][100] = {false};

int X[6] = { 0, 0, 0,  0, -1, 1};
int Y[6] = {-1, 0, 1,  0,  0, 0};
int Z[6] = { 0, 1, 0, -1,  0, 0};

bool _judge(int x, int y, int z) {
    if (x >= m || x < 0 || y >= n || y < 0 || z >= slice || z < 0)
        return false;
    if (pixel[x][y][z] == 0 || inq[x][y][z] == true)
        return false;
    return true;
}

int BFS(int x, int y, int z) {
    int ans = 0;
    queue<Node> q;
    node.x = x, node.y = y, node.z = z;
    q.push(node);
    inq[x][y][z] = true;
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        ans++;
        for (int i = 0; i < 6; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if (_judge(newX, newY, newZ)) {
                node.x = newX;
                node.y = newY;
                node.z = newZ;
                q.push(node);
                inq[newX][newY][newZ] = true;
            }
        }
    }

    if (ans >= T) return ans;
    else return 0;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d%d%d", &m, &n, &slice, &T);

    for (int z = 0; z < slice; z++) {
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                scanf("%d", &pixel[x][y][z]);
                //printf("%d\n", pixel[x][y][z]);
            }
        }
    }

    int ans = 0;
    for (int z = 0; z < slice; z++) {
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (_judge(x, y, z)) {
                    ans += BFS(x, y, z);
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}