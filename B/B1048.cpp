#include <iostream>
#include <algorithm>
using namespace std;
/*
 首先将AB的位数对其对齐B
 然后按照他给定的规则进行加密输出
 */

int main() {
    string a,b,c;
    cin>>a>>b;
    int lena=a.length(),lenb=b.length();
    if(lena<lenb){
        //补齐0
        for (int i = 0; i < lenb-lena; ++i) {
            a='0'+a;
        }
    }else if(lena>lenb){
        for (int i = 0; i < lena-lenb; ++i) {
            b='0'+b;
        }
    }
    char str[14] = {"0123456789JQK"};
    //注意这里长度发生了变化
    lenb=b.length();
    for (int j = 0; j < a.length(); ++j) {
        if((lenb-j)%2==0){
            int ans=b[j]-a[j];
            if (ans<0){
                ans+=10;
            }
            c+=str[ans];
        }else{
            c+=str[(a[j]-'0'+b[j]-'0')%13];
        }
    }
    for (int i = 0; i<c.length(); i++)
        cout << c[i];

    return 0;
}