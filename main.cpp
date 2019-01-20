#include <iostream>
using namespace std;
const int N=54;
char mp[]={'S','H','C','D','J'};
int startN[N+1],endN[N+1],nextN[N+1];//next为排序的顺序数组
int main() {
    //初始化拍的编号
    int k;
    scanf("%d",&k);
    for(int i=1;i<=N;++i){
        startN[i]=i;
    }
    //输入排序顺序
    for(int i=1;i<=N;++i){
        scanf("%d",&nextN[i]);
    }
//    用排序
    for(int i=0;i<k;++i){
        //重复k次
        for(int j=1;j<=N;++j){
            endN[nextN[j]]=startN[j];
        }
//排好了覆盖
        for(int j=1;j<=N;++j){
            startN[j]=endN[j];
        }

    }
    //i从1开始输出
    for(int i=1;i<=N;i++){
        if(i!=1)printf(" ");
        startN[i]--;
        printf("%c%d",mp[(startN[i])/13],(startN[i]%13+1));
    }
    return 0;
}
