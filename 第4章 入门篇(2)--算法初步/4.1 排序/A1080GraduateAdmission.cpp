#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct student {
    int id;
    int ge, gi, sum;
    int rank;
    int prefer[6];
}stu[40001];

struct school {
    int quota;//quota：限额
    int acceptted;
    int id[40001];
    int last;//招收的最后一个学生的id
}sch[101];

bool cmp(student a, student b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    else return a.ge > b.ge;
}

bool cmpByID(int a, int b) {
    return stu[a].id < stu[b].id;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; i++) {//初始化学校
        scanf("%d", &sch[i].quota);
        sch[i].acceptted = 0;
        sch[i].last = -1;
    }

    for (int i = 0; i < n; i++) {//初始化考生
        stu[i].id = i;
        scanf("%d %d", &stu[i].ge, &stu[i].gi);
        stu[i].sum = stu[i].ge + stu[i].gi;
        for (int j = 0; j < k; j++) {
            scanf("%d", &stu[i].prefer[j]);
        }
    }

    //排名
    sort(stu, stu+n, cmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && stu[i].sum == stu[i-1].sum && stu[i].ge == stu[i-1].ge) {
            stu[i].rank = stu[i-1].rank;
        } else {
            stu[i].rank = i;
        }
    }

    //按规则分配学校
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int preferid = stu[i].prefer[j];
            int num = sch[preferid].acceptted;
            int last = sch[preferid].last;

            if (num < sch[preferid].quota || (last != -1 && stu[last].rank == stu[i].rank)) {
                sch[preferid].last = i;
                sch[preferid].id[num] = i;
                sch[preferid].acceptted++;
                break;
            }
        }
    }

    //打印学校的生源
    for (int i = 0; i < m; i++) {
        if (sch[i].acceptted > 0) {
            //学生id从小到大排序
            sort(sch[i].id, sch[i].id+sch[i].acceptted, cmpByID);
            for (int j = 0; j < sch[i].acceptted; j++) {
                if (j != 0) printf(" ");
                printf("%d", stu[sch[i].id[j]].id);
            }
        }
        printf("\n");
    }


    return 0;
}