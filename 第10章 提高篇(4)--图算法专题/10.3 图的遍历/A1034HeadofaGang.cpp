#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

#define maxn 2010
int n, k, numPerson = 0;
map<int, string> intToString;//编号->姓名
map<string, int> stringToInt;//姓名->编号
map<string, int> Gang;

int weight[maxn];
int G[maxn][maxn];
bool vis[maxn];

int change(string str) {
    if (stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];
    } else {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}

void DFS(int nowVis, int &head, int &totalTime, int &totalPeople) {
    totalPeople++;
    vis[nowVis] = true;
    if (weight[nowVis] > weight[head]) {
        head = nowVis;
    }

    for (int i = 0; i < numPerson; i++) {
        if (G[nowVis][i] > 0) {
            totalTime += G[nowVis][i];
            G[nowVis][i] = G[i][nowVis] = 0;
            if (vis[i] == false) DFS(i, head, totalTime, totalPeople);
        }
    }
}

void DFSTrave() {
    //printf("%d\n", numPerson);
    for (int i = 0; i < numPerson; i++) {
        //printf("i = %d\n", i);
        if (vis[i] == false) {
            //printf("%d\n", i);
            int head = i, totalTime = 0, totalPeople = 0;
            DFS(i, head, totalTime, totalPeople);
            if (totalTime > k && totalPeople > 2) {
                Gang[intToString[head]] = totalPeople;
            }
        }
    }
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    cin >> n >> k;
    string name1, name2; int time;
    for (int i = 0; i < n; i++) {
        cin >> name1 >> name2 >> time;
        int id1 = change(name1); //printf("%d %d\n", id1, numPerson);
        int id2 = change(name2); //printf("%d %d\n", id2, numPerson);
        G[id1][id2] += time;
        G[id2][id1] += time;
        weight[id1] += time;
        weight[id2] += time;
    }
    DFSTrave();
    cout << Gang.size() << endl;
    for (auto it = Gang.begin(); it != Gang.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}