#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

vector<int> father, isroot;
bool cmp(int a,int b){
    return a>b;
}
int find(int x) {
    int a=x;
    while (x != father[x]) {
        x = father[x];
    }
//    while(a!=father[x]){
//        int z=a;
//        a=father[a];
//        father[z]=x;
//    }
    return x;
}

void unionFri(int a, int b) {
    int af = find(a);
    int bf = find(b);
    if (af != bf) {
        father[af] = bf;
    }
}

/*
分析：并查集。先写好init、findFather、Union。
0. 每个社交圈的结点号是人的编号，而不是课程。课程是用来判断是否处在一个社交圈的。
1. course[t]表示任意一个喜欢t活动的人的编号。如果当前的课程t，之前并没有人喜欢过，那么就course[t] = i，i为它自己的编号，表示i为喜欢course[t]的一个人的编号
2. course[t]是喜欢t活动的人的编号，那么findFather(course[t])就是喜欢这个活动的人所处的社交圈子的根结点，合并根结点和当前人的编号的结点i。即Union(i, findFather(course[t]))，把它们处在同一个社交圈子里面
3. isRoot[i]表示编号i的人是不是它自己社交圈子的根结点，如果等于0表示不是根结点，如果不等于0，每次标记isRoot[findFather(i)]++，那么isRoot保存的就是如果当前是根结点，那么这个社交圈里面的总人数
4. isRoot中不为0的编号的个数cnt就是社交圈圈子的个数
5. 把isRoot从大到小排列，输出前cnt个，就是社交圈人数的从大到小的输出顺序
 */

int main() {
    int n, cnt = 0;
    int course[1001] = {0};
    scanf("%d", &n);
    father.resize(n + 1);
    isroot.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int a, b;
        scanf("%d:", &a);
        for (int j = 0; j < a; ++j) {
            scanf("%d", &b);
            if (course[b] == 0) {
                course[b] = i;
            }
            unionFri(i, find(course[b]));
        }
    }
    for (int i = 1; i <= n; ++i) {
        isroot[find(i)]++;
    }
    for (int i = 1; i <= n; ++i) {
        if(isroot[i]!=0)cnt++;
    }
    printf("%d\n",cnt);
    sort(isroot.begin(),isroot.end(),cmp);
    for (int i = 0; i < cnt; ++i) {
        if(i!=0)printf(" ");
        printf("%d",isroot[i]);
    }
    return 0;
}
