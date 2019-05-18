#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int max_score = -1, min_score = 101;
    string max_name, min_name, max_id, min_id;
    for (int i = 0; i < n; i++) {
        string name, id;
        int score;
        cin >> name >> id >> score;
        if (score > max_score) {
            max_name = name;
            max_id = id;
            max_score = score;
        }

        if (score < min_score) {
            min_name = name;
            min_id = id;
            min_score = score;
        }
    }

    cout << max_name << " " << max_id << endl;
    cout << min_name << " " << min_id;

    return 0;
}