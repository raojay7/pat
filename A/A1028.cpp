#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

/*

 注意，按照名称的不降序排序，因为strcmp比较的是ACSII码，
 所以A < Z。写cmp函数的时候return strcmp(a.name, b.name) <= 0;
 return语句返回的是true或者false的值，所以要写 <= 0 这样的形式。
 比较ACSII码的大小，strcmp(‘a’, ‘z’)返回负值，因为a<z a – z < 0
 按照分数的不降序排序，a.score <= b.score
 */
const int maxn=100001;
struct NODE {
    int no,score;
    char name[10];
}node[maxn];
int c;
int cmp(struct NODE a, struct NODE b) {
    if (c==1){
        return a.no<b.no;
    }else if (c==2){
        if(strcmp(a.name,b.name)==0)return a.no<b.no;
        return strcmp(a.name,b.name)<=0;
    }else{
        if(a.score==b.score)return a.no<b.no;
        return a.score<=b.score;
    }
}

int main() {
    int n;
    scanf("%d %d",&n,&c);
    for (int i = 0; i < n; ++i) {
        scanf("%d %s %d",&node[i].no,node[i].name,&node[i].score);
    }
    sort(node,node+n,cmp);
    for (int i = 0; i < n; ++i) {
        printf("%06d %s %d\n",node[i].no,node[i].name,node[i].score);
    }
    return 0;
}
