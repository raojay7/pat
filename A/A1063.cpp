#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    //set的数组
    vector<set<int>> v(n);

    for (int i = 0; i < n; ++i) {
        int k,num;
        scanf("%d",&k);
        set<int> s;
        for (int j = 0; j < k; ++j) {
            scanf("%d",&num);
            //加入set
            s.insert(num);
        }
        v[i]=s;
    }

    int query;
    scanf("%d",&query);
    for (int i = 0; i < query; ++i) {
        int st1,st2;
        scanf("%d %d",&st1,&st2);
        //输出结果
        //遍历st1，然后findst2，如果找到了nc++，否则nt++
        int nc=0,nt=v[st2-1].size();
        for(auto it=v[st1-1].begin();it!=v[st1-1].end();it++){
            if(v[st2-1].find(*it)==v[st2-1].end())nt++;
            else nc++;
        }
        double res=(double)nc/nt*100;
        printf("%.1f%%\n",res);
    }
    return 0;
}
