#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
using namespace std;
/*
 * 用bfs，设立两个数组，
 * 第一个level，保存i结点的层数，
 * 为了bfs的时候可以让当前结点的层数是它的父结点层数+1，
 * 第二个数组book，
 * 保存i层所拥有的叶子结点的个数。变量maxlevel保存最大的层数
 */
int level[100],book[100],maxlevel=-1;
vector<int> v[100];
void bfs(){
    queue<int> q;
    q.push(1);
    level[1]=0;
    while(!q.empty()){
        int index=q.front();
        q.pop();
        maxlevel=max(maxlevel,level[index]);
        if(v[index].size()==0)book[level[index]]++;
        for (int i = 0; i < v[index].size(); ++i) {
            q.push(v[index][i]);
            level[v[index][i]]=level[index]+1;
        }
    }
}
int main() {
    int n,m,k,node,c;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&node,&k);
        for (int j = 0; j < k; ++j) {
            scanf("%d",&c);
            v[node].push_back(c);
        }
    }
    bfs();
    printf("%d", book[0]);
    for(int i = 1; i <= maxlevel; i++)
        printf(" %d", book[i]);
    return 0;
}



