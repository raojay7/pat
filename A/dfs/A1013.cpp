#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
/*
 统计联通分量的个数cnt，需要添加的边的个数就是cnt-1，使用dfs，对于去掉的点，将其设置为visit为true，
 然后从每个没被访问的点开始dfs统计出联通的分量
 */

int v[1010][1010];
bool visit[1010];
int n,m,k;
void dfs(int node){
    visit[node]=true;
    for (int i = 1; i <=n; ++i) {
        if(!visit[i]&&v[node][i]==1){
            dfs(i);
        }
    }
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a][b]=v[b][a]=1;
    }
    for (int i = 0; i < k; ++i) {
        fill(visit,visit+1010,false);
        int c;
        scanf("%d",&c);
        visit[c]=true;
        int cnt=0;
        for (int j = 1; j <= n; ++j) {
            if(!visit[j]){
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n",cnt-1);
    }
    return 0;
}
