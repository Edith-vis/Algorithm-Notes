#include <iostream>
using namespace std;

struct node {
    string name;
    string id;
}stu[101];

bool isExist[101] = {false};

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        string name, id;
        int score;
        cin >> name >> id >> score;
        isExist[score] = true;
        stu[score].name = name;
        stu[score].id = id;
    }

    int min, max;
    scanf("%d %d", &min, &max);
    bool flag = false;
    for (int i = max; i >= min; i--) {
        if (isExist[i]) {
            cout << stu[i].name << " " << stu[i].id << endl;
            flag = true; 
        }
    }

    if (flag == false) printf("NONE");
    return 0;
}