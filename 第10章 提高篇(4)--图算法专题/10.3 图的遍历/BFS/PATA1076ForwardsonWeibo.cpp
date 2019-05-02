#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Node{
    int id;//从1开始
    int layer;
};

#define MAXV 1010
bool inq[MAXV] = {false};
vector<Node> Adj[MAXV];
int n;

int BFS(int s, int L) {
    int num = 0;
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while (!q.empty()) {
        Node topNode = q.front();
        q.pop();
        int u = topNode.id;
        for (int i = 0; i < Adj[u].size(); i++) {
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;
            if (inq[next.id] == false && next.layer <= L) {
                num++;
                q.push(next);
                inq[next.id] = true;
            }
        }
    }

    return num;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int L;
    scanf("%d%d", &n, &L);//总人数 限制层数
    Node user;
    int numFollow, idFollow;
    for (int i = 1; i <= n; i++) {
        user.id = i;

        scanf("%d", &numFollow);
        for (int j = 0; j < numFollow; j++) {
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user);
        }
    }

    int numQuery, idQuery;
    scanf("%d", &numQuery);
    for (int i = 0; i < numQuery; i++) {
        scanf("%d", &idQuery);
        memset(inq, false, sizeof(inq));
        int num = BFS(idQuery, L);
        printf("%d\n", num);
    }

    return 0;
}