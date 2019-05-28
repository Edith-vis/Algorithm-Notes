#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person{
    int ID_Number, Virtue_Grade, Talent_Grade, total;
} temp;

bool cmp(person a, person b) {
    if (a.total != b.total) return a.total > b.total;
    else if (a.Virtue_Grade != b.Virtue_Grade) return a.Virtue_Grade > b.Virtue_Grade;
    else return a.ID_Number < b.ID_Number;
};

vector<person> sage, nobleman, fool, small;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, l, h;
    scanf("%d %d %d", &n, &l, &h);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &temp.ID_Number, &temp.Virtue_Grade, &temp.Talent_Grade);
        if (temp.Virtue_Grade >= l && temp.Talent_Grade >= l) {
            cnt++;
            temp.total = temp.Virtue_Grade + temp.Talent_Grade;
            if (temp.Virtue_Grade >= h && temp.Talent_Grade >= h) {
                sage.push_back(temp);
            } else if (temp.Virtue_Grade >= h && temp.Talent_Grade < h) {
                nobleman.push_back(temp);
            } else if (temp.Virtue_Grade >= temp.Talent_Grade) {
                fool.push_back(temp);
            } else {
                small.push_back(temp);
            }
        }
    }

    printf("%d\n", cnt);

    sort(sage.begin(), sage.end(), cmp);
    for (int i = 0; i < sage.size(); i++) {
        printf("%08d %d %d\n", sage[i].ID_Number, sage[i].Virtue_Grade, sage[i].Talent_Grade);
    }

    sort(nobleman.begin(), nobleman.end(), cmp);
    for (int i = 0; i < nobleman.size(); i++) {
        printf("%08d %d %d\n", nobleman[i].ID_Number, nobleman[i].Virtue_Grade, nobleman[i].Talent_Grade);
    }

    sort(fool.begin(), fool.end(), cmp);
    for (int i = 0; i < fool.size(); i++) {
        printf("%08d %d %d\n", fool[i].ID_Number, fool[i].Virtue_Grade, fool[i].Talent_Grade);
    }

    sort(small.begin(), small.end(), cmp);
    for (int i = 0; i < small.size(); i++) {
        printf("%08d %d %d", small[i].ID_Number, small[i].Virtue_Grade, small[i].Talent_Grade);
        if (i != small.size()-1) printf("\n");
    }

    return 0;
}