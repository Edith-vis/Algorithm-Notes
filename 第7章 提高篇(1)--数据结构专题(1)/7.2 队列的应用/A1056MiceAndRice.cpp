#include <iostream>
#include <queue>
using namespace std;

#define maxn 1010

struct Mouse {
    int weight, rank;
} mouse[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int np, ng;
    scanf("%d %d", &np, &ng);
    for (int i = 0; i < np; i++) {
        scanf("%d", &mouse[i].weight);
    }

    int order;
    queue<int> q;
    for (int i = 0; i < np; i++) {
        scanf("%d", &order);
        q.push(order);
    }

    int temp_np = np, num_group;
    while (q.size() != 1) {
        if (temp_np % ng == 0) num_group = temp_np / ng;
        else num_group = temp_np / ng + 1;

        //对每一组
        for (int i = 0; i < num_group; i++) {
            int max_mouse = q.front();//存该组冠军
            //对组内每只老鼠
            for (int j = 0; j < ng; j++) {
                if (i * ng + j >= temp_np) break;//该组个数不到ng 不能接着走循环了 此时 q.front() 为空
                int front = q.front();
                if (mouse[front].weight > mouse[max_mouse].weight) {
                    max_mouse = front;
                }
                mouse[front].rank = num_group + 1;
                q.pop();
            }
            //printf("%d----%d\n", max_mouse, temp_np);
            q.push(max_mouse);//该组冠军进入下一轮
        }

        temp_np = num_group;
    }

    mouse[q.front()].rank = 1;

    for (int i = 0; i < np; i++) {
        if (i != 0) printf(" ");
        printf("%d", mouse[i].rank);
    }

    return 0;
}