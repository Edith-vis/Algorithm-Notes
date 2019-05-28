#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student
{
    char id[14];
    int score;
    int local_number, local_rank;
    int rank;

    bool operator < (const student &A) const {
        return (score != A.score) ? score > A.score : (strcmp(id, A.id) < 0);
    }
}stu[30010];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k, num = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num++].local_number = i;
        }
        sort(stu+num-k, stu+num);
        stu[num-k].local_rank = 1;
        for (int j = 1; j < k; j++) {
            stu[num-k+j].local_rank = (stu[num-k+j].score == stu[num-k+j-1].score) ? stu[num-k+j-1].local_rank : j+1;
        }
    }
    sort(stu, stu+num);
    stu[0].rank = 1;
    for (int i = 1; i < num; i++) {
        stu[i].rank = (stu[i].score == stu[i-1].score) ? stu[i-1].rank : (i+1);
    }

    printf("%d\n", num);
    for (int i = 0; i < num; i++) {
        printf("%s %d %d %d\n", stu[i].id, stu[i].rank, stu[i].local_number, stu[i].local_rank);
    }

    return 0;
}