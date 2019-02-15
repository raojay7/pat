#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <set>
using namespace std;

/*
 把所有边存起来，把所有点的颜色存起来（存的过程中放入set统计颜色个数），
 枚举所有边，检查是否每条边的两点个颜色是否相同，
 若全不相同，则输出颜色个数，否则输出No
 */
struct node{int t1,t2;};
int main() {
    int n,m;
    cin>>n>>m;
    vector<node> v(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&v[i].t1,&v[i].t2);
    }
    int k;
    cin>>k;
    while(k--){
        int a[10009]={0};
        set<int> se;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&a[i]);
            se.insert(a[i]);
        }
        bool flag=true;
        //枚举m条边
        for (int i = 0; i < m; ++i) {
            if(a[v[i].t1]==a[v[i].t2]){
                flag=false;
                break;
            }
        }
        if(flag){
            printf("%d-coloring\n",se.size());
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
