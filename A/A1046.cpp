#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100005;
int dis[MAXN],A[MAXN];//A存放距离值
int main() {
//  dis表示1号结点到当前结点
//  sum可以开始得到，对于left-right其值就是sum-(dis[right]-dis[left])与dis[right]-dis[left]的最小值
    int sum=0,query,left,right,n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        //先计算sum和dis
        scanf("%d",&A[i]);
        sum+=A[i];
        dis[i]=sum;
    }
    scanf("%d",&query);
    for(int i=1;i<=query;++i){
        scanf("%d %d",&left,&right);
        if (left>right)swap(left,right);
        int temp;
        temp=dis[right-1]-dis[left-1];
        printf("%d\n",min(temp,sum-temp));
    }
    return 0;
}
