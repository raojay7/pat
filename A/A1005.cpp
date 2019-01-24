#include <iostream>
#include <algorithm>
using namespace std;
/*
 计算一个数字的各位之和
 */

int main() {

    string a;
    cin>>a;
    int ans=0;
    for (int i = 0; i < a.length(); ++i) {
        ans+=(a[i]-'0');
    }

    string num[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string res=to_string(ans);
    cout<<num[res[0]-'0'];
    for (int j = 1; j < res.length(); ++j) {
        cout<<" "<<num[res[j]-'0'];
    }
    return 0;
}