https://www.luogu.com.cn/problemnew/solution/P1434

## First way: DFS
##### Note
1. every point should be checked. i.e., `DFS(i, j)` for every `i` and `j`.
2. 高的点不会在递归中调用DFS, 所以不用保存经过路径

## Second way: 线性动态规划
##### Note
1. 将高度排序, 从低到高进行赋值.
2. 排序可以用STL里的 `priority_queue`

// TODO: priority_queue 的用法