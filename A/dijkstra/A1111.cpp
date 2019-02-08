#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

/*
 两遍dijkstr
 */
const int inf = 999999999;
int dis[510], Time[510], dispre[510], timepre[510], weight[510], NodeNum[510];
int e[510][510], w[510][510];
vector<int> dispath, timepath;
int st, fin;
bool visit[510];

void dfsdispath(int v) {
    dispath.push_back(v);
    if (v == st)return;
    dfsdispath(dispre[v]);
}

void dfstimepath(int v) {
    timepath.push_back(v);
    if (v == st)return;
    dfstimepath(timepre[v]);

}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    for (int i = 0; i < m; ++i) {
        int a, b, flag, length, time;
        scanf("%d%d%d%d%d", &a, &b, &flag, &length, &time);
        e[a][b] = length;
        w[a][b] = time;
        if (flag != 1) {
            e[b][a] = length;
            w[b][a] = time;
        }
    }
    scanf("%d%d", &st, &fin);
    //开始
    dis[st] = 0;
    for (int i = 0; i < n; ++i) {
        dispre[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; ++j) {
            if (!visit[j] && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)break;
        visit[u] = true;
        for (int v = 0; v < n; ++v) {
            if (!visit[v] && e[u][v] != inf) {
                if (e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    dispre[v] = u;
                    weight[v] = w[u][v] + weight[u];
                } else if (e[u][v] + dis[u] == dis[v] && weight[v] > w[u][v] + weight[u]) {
                    dispre[v] = u;
                    weight[v] = w[u][v] + weight[u];
                }
            }
        }
    }

    dfsdispath(fin);

    Time[st] = 0;
    fill(visit, visit + 510, false);
    for (int i = 0; i < n; ++i) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; ++j) {
            if (!visit[j] && Time[j] < minn) {
                u = j;
                minn = Time[j];
            }
        }
        if (u == -1)break;
        visit[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visit[v] && w[u][v] != inf) {
                if (w[u][v] + Time[u] < Time[v]) {
                    Time[v] = w[u][v] + Time[u];
                    timepre[v] = u;
                    NodeNum[v] = NodeNum[u] + 1;
                } else if (w[u][v] + Time[u] == Time[v] && NodeNum[u] + 1 < NodeNum[v]) {
                    timepre[v] = u;
                    NodeNum[v] = NodeNum[u] + 1;
                }
            }
        }
    }
    dfstimepath(fin);
    printf("Distance = %d", dis[fin]);
    if (dispath == timepath) {
        printf("; Time = %d: ", Time[fin]);
    } else {
        printf(": ");
        for (int i = dispath.size() - 1; i >= 0; i--) {
            printf("%d", dispath[i]);
            if (i != 0) printf(" -> ");
        }
        printf("\nTime = %d: ", Time[fin]);
    }
    for (int i = timepath.size() - 1; i >= 0; i--) {
        printf("%d", timepath[i]);
        if (i != 0) printf(" -> ");
    }
    return 0;
}



