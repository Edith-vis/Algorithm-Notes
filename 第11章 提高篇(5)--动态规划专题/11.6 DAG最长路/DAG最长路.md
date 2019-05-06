- 用递归计算DAG的最长路
    ```c++
    //状态：dp[i]表示从i号顶点出发能获得的最长路径长度
    //边界：出度为0的顶点的dp值为0 可以将整个dp数组初始化为0
    int DP(int i) {
        if (dp[i] > 0) return dp[i];
        for (int j = 0; j < n; j++) {
            if (G[i][j] != INF) {
                dp[i] = max(dp[i], G[i][j] + DP(j));
            }
        }
        return dp[i];
    }
    ```
- 求解最长路径
    ```c++
    int choice[maxn];//记录最长路径上顶点的后继顶点
    int DP(int i) {
        if (dp[i] > 0) return dp[i];
        for (int j = 0; j < n; j++) {
            if (G[i][j] != INF) {
                int temp = DP(j) + G[i][j];//单独计算，防止if中调用DP函数两次
                if (temp > dp[i]) {
                    dp[i] = temp;//覆盖dp[i]
                    choice[i] = j;//i号顶点的后继顶点是j
                }
            }
        }

        return dp[i];
    }

    //调用printPath函数前需要先得到最大的dp[i]，然后将i作为路径起点传入
    void printPath(int i) {
        print("%d");
        while(choice[i] != -1) {//choice数组初始化为-1
            i = choice[i];
            print("->%d", i);
        }
    }
    ```
- 如果DAG中有多条路径，如何选取字典序最小的那一条？  
  只需要令dp[i]表示从i号顶点出发能获得的最长路径长度，让遍历i的邻接点的顺序从小到大即可。  
  不能令dp[i]表示以i号顶点结尾能获得的最长路径长度，由于字典序的大小总是先根据序列中较前的部分来判断，因此序列中越靠前的顶点，其dp值应当越后计算。
- 固定终点，求DAG的最长路径长度
  ```c++
  //状态:令dp[i]表示从i号顶点出发到达终点T能获得的最长路径长度
  //边界：dp[T] = 0 不能再将dp数组初始化为0，应将dp数组初始化为一个负的大数，来保证“无法到达终点”的含义得以表达（设置为正的INF会影响最长路径的求解）
  //设置一个vis数组表示顶点是否已经被计算
    int DP(int i) {
        if (vis[i]) return dp[i];
        vis[i] = true;
        for (int j = 0; j < n; j++) {
            if (G[i][j] != INF) {
                dp[i] = max(dp[i], DP(j) + G[i][j]);
            }
        }

        return dp[i];
    }
  ```