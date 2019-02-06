#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

/*
 dijkstra算法
 加上一个边权，并在用dfs的时候计算最小花费
 */
const int inf = 99999999;
int n, m, s, d;
vector<int> pre[510];
vector<int> path, tempPath;
int e[510][510], cost[510][510], dis[510];
bool visit[510];
int mincost = inf;

void dfs(int v) {
    tempPath.push_back(v);//这个放的位置很重要，一定要在判断之前push，如果一开始进入的就是自身他就无法push
    //递归到了自身
    if (v == s) {
        int tempcost = 0;
        for (int i = tempPath.size() - 1; i > 0; i--) {
            int id = tempPath[i], nextid = tempPath[i - 1];
            tempcost += cost[id][nextid];
        }
        if (tempcost < mincost) {
            path = tempPath;
            mincost = tempcost;
        }
        tempPath.pop_back();
        return;
    }


    for (int i = 0; i < pre[v].size(); ++i) {
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &d);
    fill(dis, dis + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    //初始化边和边权
    for (int i = 0; i < m; ++i) {
        int c1, c2, distance, cos;
        scanf("%d %d %d %d", &c1, &c2, &distance, &cos);
        e[c1][c2] = e[c2][c1] = distance;
        cost[c1][c2] = cost[c2][c1] = cos;
    }

    dis[s] = 0;
    pre[s].push_back(s);
    for (int i = 0; i < n; ++i) {
        //从未访问的点中找到距离最小的一个u
        int u = -1, minn = inf;
        for (int j = 0; j < n; ++j) {
            if (!visit[j] && dis[j] < minn) {
                minn=dis[j];
                u = j;
            }
        }
        if (u == -1)break;
        visit[u] = true;
        //从u出发能访问到的并且没有访问过的点，并且更小才更新
        for (int v = 0; v < n; ++v) {
            if (!visit[v] && e[u][v] != inf) {
                if (e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    pre[v].clear();//只推入一个
                    pre[v].push_back(u);
                }else if(e[u][v] + dis[u] == dis[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }


    dfs(d);
    //打印结果
    for (int i = path.size() - 1; i >=0; --i) {
        printf("%d ", path[i]);
    }
    printf("%d %d", dis[d], mincost);
    return 0;
}



