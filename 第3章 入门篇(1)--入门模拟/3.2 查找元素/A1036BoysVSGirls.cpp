#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    string fname, fid; int fgrade = -1;
    string mname, mid; int mgrade = 101;
    for (int i = 0; i < n; i++) {
        string name, gender, id;
        int grade;
        cin >> name >> gender >> id >> grade; 
        if (gender == "F") {
            if (grade > fgrade) {
                fname = name;
                fid = id;
                fgrade = grade;
            } 
        } else {
            if (grade < mgrade) {
                mname = name;
                mid = id;
                mgrade = grade;
            }
        }
    }

    if (fgrade == -1) printf("Absent\n");
    else cout << fname << " " << fid << endl;

    if (mgrade == 101) printf("Absent\n");
    else cout << mname << " " << mid << endl;

    if (fgrade == -1 || mgrade == 101) printf("NA");
    else cout << (fgrade - mgrade);

    return 0;
}