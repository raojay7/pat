#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
 将时间都转换为总秒数，最早和最迟的时间保存在变量minn和maxn中，
 并同时保存当前最早和最迟的人的ID，最后输出
 */


int main() {
    int m;
    scanf("%d",&m);
    string unlocked,locked;
    int maxN=INT_MIN,minN=INT_MAX;
    for (int i = 0; i < m; ++i) {
        int h1,m1,s1,h2,m2,s2;
        string t;
        cin>>t;
        scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int tempIn=h1*3600+m1*60+s1;
        int tempOut=h2*3600+m2*60+s2;
        if(tempIn<minN){
            minN=tempIn;
            unlocked=t;
        }
        if (tempOut>maxN){
            maxN=tempOut;
            locked=t;
        }

    }
    cout<<unlocked<<" "<<locked;
    return 0;
}
