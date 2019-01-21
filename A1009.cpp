#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
//存放第一个多项式的值
struct Poly{
    int exp;
    double cof;
}poly[1001];

const int maxN=2001;
double p[maxN]={};
int main() {
    //输入多项式
    int m,n,count=0;

    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %lf",&poly[i].exp,&poly[i].cof);//暂存
    }

    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int zhishu;
        double xishu;
        scanf("%d %lf",&zhishu,&xishu);
        //循环相乘
        for (int j = 0; j < m; ++j) {
            p[zhishu+poly[j].exp]+=(xishu*poly[j].cof);
        }
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
