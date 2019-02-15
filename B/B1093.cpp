#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <climits>
#include <string>
using namespace std;

/*
 用数组hash标记一下是否是第一次输出即可（字符本身是一个ASCII码值，可当作整数用）
 */
int main() {
    string s1,s2,s;
    int hash[200]={0};
    getline(cin,s1);
    getline(cin,s2);
    s=s1+s2;
    for (int i = 0; i < s.size(); ++i) {
        if(hash[s[i]]==0)cout<<s[i];
        hash[s[i]]=1;
    }
    return 0;
}
