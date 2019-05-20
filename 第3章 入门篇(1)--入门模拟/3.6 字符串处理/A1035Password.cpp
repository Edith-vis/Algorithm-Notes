#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct user{
    string id, pwd;
}users[1010];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string id, pwd;
        cin >> id >> pwd;
        bool flag = false;
        for (int i = 0; i < pwd.length(); i++) {
            if (pwd[i] == '1') {
                flag = true;
                pwd[i] = '@';
            } else if (pwd[i] == '0') {
                flag = true;
                pwd[i] = '%';
            } else if (pwd[i] == 'l') {
                flag = true;
                pwd[i] = 'L';
            } else if (pwd[i] == 'O') {
                flag = true;
                pwd[i] = 'o';
            }
        }
        if (flag) {
            users[cnt].id = id;
            users[cnt].pwd = pwd;
            cnt++;
        }
    }

    if (cnt == 0) {
        if (n == 1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", n);
        }
    } else {
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++) {
            cout << users[i].id << " " << users[i].pwd << endl;
        }
    }

    return 0;
}