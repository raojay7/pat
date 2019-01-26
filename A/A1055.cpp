#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

/*
 首先写好比较函数
 在建立一个结果数组，对于每个查询，都直接遍历前M个查询结果
 最后直接输出
 */
const int maxn=100001;
struct  NODE{
    int age,net_worth;
    char name[10];
}node[maxn];
int cmp(struct NODE a, struct NODE b) {
    if (a.net_worth==b.net_worth){
        if(a.age==b.age){
            return strcmp(a.name,b.name)<=0;
        }
        return a.age<=b.age;
    }else{
        return a.net_worth>=b.net_worth;
    }
}

int main() {
    int N,K;
    scanf("%d %d",&N,&K);
    for (int i = 0; i < N; ++i) {
        scanf("%s %d %d",node[i].name,&node[i].age,&node[i].net_worth);
    }
    sort(node,node+N,cmp);
    int M,amin,amax;
    vector<NODE> v[K];
    for (int i = 0; i < K; ++i) {
        scanf("%d %d %d",&M,&amin,&amax);
        int cnt=0;
        for (int j = 0; j < N; ++j) {
            if(node[j].age>=amin&&node[j].age<=amax){
                v[i].push_back(node[j]);
                cnt++;
            }
            if (cnt==M)break;
        }
    }

    for (int i = 0; i < K; ++i) {
        printf("Case #%d:\n",(i+1));
        if(v[i].empty())printf("None\n");
        for (int j = 0; j < v[i].size(); ++j) {
            printf("%s %d %d\n",v[i][j].name,v[i][j].age,v[i][j].net_worth);
        }
    }
    return 0;
}
