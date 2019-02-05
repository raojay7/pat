#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

/*
 这道题考的是DFS+剪枝，我认为主要剪枝的地方有三个：
1. tempK==K但是tempSum!=n的时候需要剪枝
2. 在枚举的时候，按顺序枚举，上界或者下界可进行剪枝
3. 当且仅当tempSum + v[index] <= n时，进行下一层的DFS，而不要进入下一层DFS发现不满足条件再返回，这样开销会比较大
 */
int n,k,p,maxFacSum=-1;
vector<int> v,ans,tempAns;//v是存对应的n[i]^p的，ans是最终结果，tempAns是临时存入的
void init(){
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}

void dfs(int index,int tempSum,int tempK,int facSum){
    if(tempK==k){
        if (tempSum==n&&facSum>maxFacSum){
            ans=tempAns;
            maxFacSum=facSum;
        }
        return;//剪枝
    }
    while(index>=1){
        if(tempSum+v[index]<=n){
            tempAns[tempK]=index;
            dfs(index,tempSum+v[index],tempK+1,facSum+index);
        }
        if(index==1)return;
        index--;
    }
}
int main() {
    scanf("%d %d %d",&n,&k,&p);
    init();
    tempAns.resize(k);//这个很重要
    dfs(v.size()-1,0,0,0);
    if(maxFacSum==-1){
        printf("Impossible");
        return 0;
    }
    printf("%d = ",n);
    for (int i = 0; i < ans.size(); ++i) {
        if(i!=0)printf(" + ");
        printf("%d^%d",ans[i],p);
    }
    return 0;
}



