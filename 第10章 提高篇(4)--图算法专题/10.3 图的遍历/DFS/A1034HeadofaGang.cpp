#include <iostream>
#include <map>
#include <string>
using namespace std;

const int maxn = 2010;
int n, k;
int personNum = 0;
int G[maxn][maxn] = {{0}}, weight[maxn] = {0};
bool vis[maxn] = {false};

map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;

void DFS(int u, int &head, int &memberNum, int &totalTime) {
    vis[u] = true;
    memberNum++;
    if (weight[u] > weight[head]) {
        head = u;
    }

    for (int v = 0; v < personNum; v++) {
        if (G[u][v] > 0) {
            totalTime += G[u][v];
            G[u][v] = G[v][u] = 0;
            if (vis[v] == false) {
                DFS(v, head, memberNum, totalTime);
            }
        }
    }
}

void DFSTrave() {
    for (int u = 0; u < personNum; u++) {
        if (vis[u] == false) {
            int head = u, totalTime = 0, memberNum = 0;
            DFS(u, head, memberNum, totalTime);
            if (memberNum > 2 && totalTime > k) {
                Gang[intToString[head]] = memberNum;
            }
        }
    }
}

int change(string str) {
    if (stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];
    } else {
        stringToInt[str] = personNum;
        intToString[personNum] = str;
        return personNum++;
    }
}

string str1, str2;
int time;
int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        cin >> str1 >> str2 >> time;
        int id1 = change(str1);
        int id2 = change(str2);
        G[id1][id2] += time; G[id2][id1] += time;
        weight[id1] += time; weight[id2] += time;
    }
    DFSTrave();

    printf("%d\n", Gang.size());
    map<string, int>::iterator it;
    for (it = Gang.begin(); it != Gang.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}