#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct node {
    char name[10];
    int age, worth;
};

bool cmp (node a, node b) {
    if (a.worth != b.worth) return a.worth > b.worth;
    else if (a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    vector<node> people(n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", people[i].name, &people[i].age, &people[i].worth);
    }

    sort(people.begin(), people.end(), cmp);

    int num, min, max;
    for (int i = 1; i <= k; i++) {
        scanf("%d %d %d", &num, &min, &max);
        if (i != 1) printf("\n");

        printf("Case #%d:", i);

        

        bool flag = false;
        int cnt = 0;
        for (int j = 0; j < people.size() && cnt < num; j++) {
            if (people[j].age >= min && people[j].age <= max) {
                printf("\n%s %d %d", people[j].name, people[j].age, people[j].worth);
                cnt++;
                flag = true;
            }
        }

        if (flag == false) printf("\nNone");

    }

    return 0;
}