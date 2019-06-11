#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int id;
    int layer;
} user;

#define maxn 1010
int n, L;
vector<node> people[maxn];
bool inq[maxn] = {false};

//起始节点为start，层数上限为L
int BFS(int s) {
    int numForward = 0;
    queue<node> q;

    node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;

    while (!q.empty()) {
        node front = q.front();
        q.pop();
        int id = front.id;
        for (int i = 0; i < people[id].size(); i++) {
            node next = people[id][i];
            next.layer = front.layer + 1;
            if (inq[next.id] == false && next.layer <= L) {
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &L);
    int m, id;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        user.id = i;
        for (int j = 0; j < m; j++) {
            scanf("%d", &id);
            people[id].push_back(user);
        }
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        memset(inq, false, sizeof(inq));
        scanf("%d", &id);
        printf("%d\n", BFS(id));
    }
    return 0;
}