#include <iostream>
#include <algorithm>
using namespace std;
/*
 将a+b相加，然后得到一个新的数字，判断其小于0否，如果小于就取其绝对值并输出
 只要当前位的下标i满足(i + 1) % 3 == len % 3并且i不是最后一位，就在逐位输出的时候在该位输出后的后面加上一个逗号
 */

int main() {
    int a,b;
    cin>>a>>b;
    string c=to_string(a+b);
    int len=c.length();
    for (int i = 0; i < len; ++i) {
        cout<<c[i];
        if(c[i]=='-')continue;
        if((i+1)%3==len%3&&i!=len-1)cout<<',';
    }
    return 0;
}