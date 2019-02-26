#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <set>

using namespace std;
/*
 用结构体数组存储这个链表，大小为maxn = 100000，node[i]表示地址为i的结点。
 在结构体中定义一个num变量，将num变量先初始化为2 * maxn。
 通过改变num变量的值最后sort排序来改变链表的顺序。
 将没有删除的结点的num标记为cnt1，cnt1为当前没有删除的结点的个数；
 将需要删除的结点的num标记为maxn + cnt2，cnt2表示当前删除了的结点的个数，
 因为一开始初始化为了2 * maxn，所以我们可以通过对num排序达到：num = 0~maxn为不删除结点，
 num = maxn~2maxn为删除结点，num = 2maxn为无效结点
 这样sort后就会按照需要输出的顺序将结点排序，我们只需要输出前cnt1+cnt2个结点即可
 */
const int maxn = 100000;
struct NODE {
    int address, key, next, num = 2 * maxn;
} node[maxn];
bool exist[maxn];

bool cmp(NODE n1, NODE n2) {
    return n1.num < n2.num;
}

int main() {
    int begin,n,cnt1=0,cnt2=0,a;
    scanf("%d%d",&begin,&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a);
        scanf("%d%d",&node[a].key,&node[a].next);
        node[a].address=a;
    }
    for (int i = begin; i !=-1 ; i=node[i].next) {
        if(!exist[abs(node[i].key)]){
            exist[abs(node[i].key)]=true;
            node[i].num=cnt1;
            cnt1++;
        }else{
            node[i].num=maxn+cnt2;
            cnt2++;
        }
    }
    sort(node,node+maxn,cmp);
    int cnt=cnt1+cnt2;
    for (int i = 0; i < cnt; ++i) {
        if(i!=cnt1-1&&i!=cnt-1){
            printf("%05d %d %05d\n",node[i].address,node[i].key,node[i+1].address);
        }else{
            printf("%05d %d -1\n",node[i].address,node[i].key);
        }
    }
    return 0;
}
