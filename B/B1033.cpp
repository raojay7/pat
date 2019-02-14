#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
//要一行一行读入
int main() {
    string s1,s2;
    map<char,bool> m;
    getline(cin,s1);
    getline(cin,s2);
    // cin>>s1>>s2;
    for (int i = 0; i < s1.length(); ++i) {
        m[(char)toupper(s1[i])]=true;
    }
    for (int j = 0; j < s2.length(); ++j) {
        if(m.find('+')!=m.end()){
            if(s2[j]<='Z'&&s2[j]>='A')continue;
        }
        if(m.find((char)toupper(s2[j]))==m.end())
            cout<<s2[j];
    }
    return 0;
}



