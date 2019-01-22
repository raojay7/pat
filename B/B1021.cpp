#include <iostream>
#include <algorithm>
using namespace std;
/*
直接开一个数组
下标代表数字，内容代表次数
注意字符串处理要用字符串，如果是转换为数字容易出错
 */
int main() {
    int a[10]={0};
    string s;
    cin>>s;
    for (int i = 0; i < s.length(); i++)
        a[s[i] - '0']++;
    for (int i = 0; i < 10; ++i) {
        if(a[i]!=0)printf("%d:%d\n",i,a[i]);
    }
    return 0;
}