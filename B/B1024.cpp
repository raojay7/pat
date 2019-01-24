#include <iostream>
using namespace std;
/*
 n保存E后面的字符串所对应的数字，t保存E前面的字符串，不包括符号位。
 当n<0时表示向前移动，那么先输出0. 然后输出abs(n)-1个0，
 然后继续输出t中的所有数字；
 当n>0时候表示向后移动，那么先输出第一个字符，然后将t中尽可能输出n个字符，
 如果t已经输出到最后一个字符(j == t.length())那么就在后面补n-cnt个0，
 否则就补充一个小数点. 然后继续输出t剩余的没有输出的字符
 */

int main() {
    string s;
    cin>>s;
    int i=0;
    while(s[i]!='E')i++;//找到E，然后切分
    string t=s.substr(1,i-1);//从1开始取i-1个
    int n=stoi(s.substr(i+1));//从i+1开始
    if(s[0]=='-')cout<<"-";
    if(n<0){
        cout<<"0.";
        for (int j = 0; j < abs(n)-1; ++j) {
            cout<<"0";
        }
        //只输出数字
        for (int j = 0; j < t.length(); ++j) {
            if(t[j]!='.')cout<<t[j];
        }
    }else{
        cout<<t[0];
        int j = 2,cnt;
        for (cnt=0; j < t.length()&&cnt<n; ++j,++cnt) {
            cout<<t[j];
        }
        if(j==t.length()){
            for (int k = 0; k < n-cnt; ++k) {
                cout<<"0";
            }
        }else{
            cout<<".";
            for (int k = j; k < t.length(); ++k) {
                cout<<t[k];
            }
        }
    }
    return 0;
}