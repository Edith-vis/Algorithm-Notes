#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    string unlock_id, unlock_time = "23:59:59";
    string lock_id, lock_time = "00:00:00";
    for (int i = 0; i < n; i++) {
        string id;
        string sign_in, sign_out;
        cin >> id >> sign_in >> sign_out;
        if (sign_in < unlock_time) {
            unlock_id = id;
            unlock_time = sign_in;
        }

        if (sign_out > lock_time) {
            lock_id = id;
            lock_time = sign_out;
        }
    }

    cout << unlock_id << " " << lock_id;

    return 0;
}