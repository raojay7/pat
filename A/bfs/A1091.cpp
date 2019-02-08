#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
/*
 三维的广度优先搜索
 XYZ三个数组判断方向，对每一个点广度优先累计肿瘤块的大小，
 如果大于等于t就把结果累加。用visit数组标记当前的点有没有被访问过，
 被访问过的结点是不会再访问的。。judge判断是否超过了边界，或者是否当前结点为0不是肿瘤
 */
int m,n,l,t;
//方向数组
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
//三维数组
struct Node{
    int x,y,z;
};
int arr[1300][130][80];
bool visited[1300][130][80];
bool judge(int x,int y,int z){
    if(x<0||y<0||z<0||x>=m||y>=n||z>=l)return false;
    return !(arr[x][y][z] == 0 || visited[x][y][z]);
}

int bfs(int x,int y,int z){
    queue<Node> q;
    int count=0;
    Node tmp;
    tmp.x=x;
    tmp.y=y;
    tmp.z=z;
    q.push(tmp);
    visited[x][y][z]=true;
    while(!q.empty()){
        Node n=q.front();
        q.pop();
        count++;
        //向6个方向查找
        for(int i=0;i<6;i++){
            int newx=dx[i]+n.x;
            int newy=dy[i]+n.y;
            int newz=dz[i]+n.z;
            if(judge(newx,newy,newz)){
                visited[newx][newy][newz]=true;
                tmp.x=newx,tmp.y=newy,tmp.z=newz;
                q.push(tmp);
            }
        }
    }
    if(count>=t){
        return count;
    }else{
        return 0;
    }
}
int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                scanf("%d",&arr[j][k][i]);
            }
        }
    }

    int ans=0;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if(arr[j][k][i]==1 && !visited[j][k][i]){
                    ans+=bfs(j,k,i);
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}



