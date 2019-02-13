#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/*
 只能有一个P一个T，中间末尾和开头可以随便插入A。
 但是必须满足开头的A的个数 * 中间的A的个数 = 结尾的A的个数，而且P和T中间不能没有A
*/
 int main(){
    int n,p=0,t=0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        map<char,int> mp;
        string str;
        cin>>str;
        for (int j = 0; j < str.length(); ++j) {
            mp[str[j]]++;
            if(str[j]=='P')p=j;
            if(str[j]=='T')t=j;
        }
        if (mp['P']==1&&mp['T']==1&&mp['A']!=0&&mp.size()==3&&t-p!=1&&p*(t-p-1)==(str.length()-t-1)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
