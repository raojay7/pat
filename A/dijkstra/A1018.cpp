#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

/*
 dijkstra算法，加计算点权
 */
const int inf = 99999999;
vector<int> pre[510];
int dis[510], e[510][510], weight[510];
bool visit[510];
int minback = inf, minneed = inf;
vector<int> path, tempPath;
int cmax, n, s, m;

void dfs(int v) {
    tempPath.push_back(v);
    if (v == 0) {
        int need = 0, back = 0;
        //遍历当时的路径计算最小带回和需要，如果weight为正，back累积，为负，减去当前的back
        for (int i = tempPath.size() - 1; i >= 0; --i) {
            int id = tempPath[i];
            if (weight[id] > 0) {
                back += weight[id];
            } else {
                if (back > (0 - weight[id])) {
                    back += weight[id];
                } else {
                    //不满足需要
                    need += (0 - weight[id]) - back;
                    back = 0;
                }
            }
        }
        if (need < minneed) {
            minneed = need;
            minback = back;
            path = tempPath;
        } else if (need == minneed) {
            if (back < minback) {
                minback = back;
                path = tempPath;
            }
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
    fill(dis, dis + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &s, &m);
    int curr;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &curr);
        weight[i] = curr - cmax / 2;
    }
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }

    dis[0] = 0;
    //开始dijkstra,这里有n这个点，一开始忘记了
    for (int i = 0; i <= n; ++i) {
        //找u
        int u = -1, minn = inf;
        for (int j = 0; j <= n; ++j) {
            if (!visit[j] && dis[j] < minn) {
                minn = dis[j];
                u = j;
            }
        }
        //找不到返回
        if (u == -1)break;
        visit[u] = true;
        //u出发找邻接的点
        for (int v = 0; v <= n; ++v) {
            if (!visit[v] && e[u][v] != inf) {
                if (e[u][v] + dis[u] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (e[u][v] + dis[u] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }

    dfs(s);
    printf("%d ", minneed);
    for (int i = path.size() - 1; i >= 0; --i) {
        if (i != path.size() - 1)printf("->");
        printf("%d", path[i]);
    }
    printf(" %d", minback);
    return 0;
}



