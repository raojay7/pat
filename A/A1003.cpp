#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

/*
 使用dijkstra算法扫描一遍
 同时利用nums数组记录最短路径的个数以及w数组记录最多的救援队
 条件为：dis[u]+e[u][v]==dis[v]在更新
 nums初始化为nums[source]=1,如果相同在加一个
 */
const int inf=99999999;
int n,m,c1,c2;
int e[510][510],nums[510],dis[510],weight[510],w[510];
bool visit[510];
int main() {
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    //初始化邻接矩阵和dis数组，由于visit在全局变量以及初始化
    fill(e[0],e[0]+510*510,inf);
    fill(dis,dis+510,inf);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&weight[i]);
    }
    int a,b,l;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d",&a,&b,&l);
        e[b][a]=e[a][b]=l;
    }

    //初始化信息
    nums[c1]=1;
    dis[c1]=0;
    w[c1]=weight[c1];
    //dijkstra开始
    for (int i = 0; i < n; ++i) {
        //从未被访问的集合中挑一个最小的u
        int u=-1,minn=inf;
        for (int j = 0; j < n; ++j) {
            if(!visit[j]&&dis[j]<minn){
                minn=dis[j];
                u=j;
            }
        }
        if (u==-1)break;
        visit[u]=true;
        for (int v = 0; v < n; ++v) {
            //从u出发能到达的且未访问过的所有点v
            if(!visit[v]&&e[u][v]!=inf) {
                if (e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    w[v] = w[u] + weight[v];
                    nums[v] = nums[u];
                } else if (e[u][v] + dis[u] == dis[v]) {
                    nums[v] = nums[v]+nums[u] ;
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                }
            }
        }
    }
    printf("%d %d",nums[c2],w[c2]);
    return 0;
}



