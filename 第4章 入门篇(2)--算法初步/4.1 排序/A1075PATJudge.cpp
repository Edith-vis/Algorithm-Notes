#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define maxn 10001

int full[6] = {0};

struct node {
    int uid;
    int score[6];//score == -1表示该题没有提交 score == 0 该题出现无法通过编译的提交
    int total_score;
    int perfect;
    bool flag;//是否可以通过编译器有分数
}stu[maxn];

bool cmp(node a, node b) {
    if (a.total_score != b.total_score) return a.total_score > b.total_score;
    else if (a.perfect != b.perfect) return a.perfect > b.perfect;
    else return a.uid < b.uid;
}



int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &full[i]);
    }
    
    for (int i = 0; i <= n; i++) {
        stu[i].uid = i;
        memset(stu[i].score, -1, sizeof(stu[i].score));
        stu[i].total_score = 0;
        stu[i].perfect = 0;
        stu[i].flag = false;
    }

    for (int i = 0; i < m; i++) {
        int uid, pid, score;
        scanf("%d %d %d", &uid, &pid, &score);

        if (score != -1) stu[uid].flag = true;//该考生可以参与排名
        
        if (score == -1 && stu[uid].score[pid] == -1) {//该题提交了但未通过编译
            stu[uid].score[pid] = 0;
        }

        if (score == full[pid] && stu[uid].score[pid] < full[pid]) {//!第一次得满分再++
            stu[uid].perfect++;
        }

        //最后再更新分数
        if (score > stu[uid].score[pid]) {
            stu[uid].score[pid] = score;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (stu[i].score[j] != -1) {
                stu[i].total_score += stu[i].score[j];
            }
        }
    }

    sort(stu+1, stu+n+1, cmp);//id == 0的空考生应该会被排到后面去

    int rank = 1;
    for (int i = 1; i <= n && stu[i].flag == true; i++) {
        if (i > 1 && stu[i].total_score < stu[i-1].total_score) {
            rank = i;
        }
        printf("%d %05d %d", rank, stu[i].uid, stu[i].total_score);

        for (int j = 1; j <= k; j++) {
            if (stu[i].score[j] == -1) {//没提交过
                printf(" -");
            } else {
                printf(" %d", stu[i].score[j]);
            }
        }
        printf("\n");
    }
    return 0;
}