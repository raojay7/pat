#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxN=1001;
double p[maxN]={};
int main() {
    //输入多项式
    int k,count=0;
    int zhishu;
    double xishu;
    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %lf",&zhishu,&xishu);
        p[zhishu]+=xishu;
    }

    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %lf",&zhishu,&xishu);
        p[zhishu]+=xishu;
    }
    //计算count
    for (int j = 0; j <=maxN; ++j) {
        if (p[j]!=0)count++;
    }
    //输出
    printf("%d",count);
    for (int l = maxN-1; l >=0 ; --l) {
        if(p[l]!=0)printf(" %d %.1f",l,p[l]);
    }
    return 0;
}
