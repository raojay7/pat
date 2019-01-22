#include <iostream>
#include <algorithm>
using namespace std;
/*
 直接用字符串输入直接相加就可以
 */

int main() {
    string str[10] =  {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string s;
    cin>>s;
    int sum=0;
    for (int i = 0; i < s.length(); ++i) {
        sum+=s[i]-'0';
    }
    string num1=to_string(sum);
    for (int j = 0; j < num1.length(); ++j) {
        if (j!=0)cout<<" ";
        cout<<str[num1[j]-'0'];
    }
    return 0;
}