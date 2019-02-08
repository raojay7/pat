#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

/*
 weibo关注,直接反着建立图,然后查询几次就几次bfs可以得到答案
 7 3
 3 2 3 4
 0
 2 5 6
 2 3 1
 2 3 4
 1 4
 1 5
 2 2 6
 */
int n, l;
vector<int> graph[1010];

int bfs(int v) {
    queue<int> q;
    bool visited[1010]={false};
    q.push(v);
    visited[v]=true;
    int count = 0, layer = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int node = q.front();
            q.pop();
            for (int j = 0; j < graph[node].size(); ++j) {
                if (!visited[graph[node][j]] && layer < l) {
                    count++;
                    q.push(graph[node][j]);
                    visited[graph[node][j]]= true;
                }
            }
        }
        layer++;
    }
    return count;
}

int main() {

    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; ++i) {
        int followers;
        scanf("%d", &followers);
        for (int j = 0; j < followers; ++j) {
            int node;
            scanf("%d", &node);
            graph[node].push_back(i);
        }
    }
    int q, qnode;
    scanf("%d", &q);
    for (int k = 0; k < q; ++k) {
        scanf("%d", &qnode);
        int ans = bfs(qnode);
        printf("%d\n", ans);
    }
    return 0;
}



