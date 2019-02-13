#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    string str;
    cin>>str;
    map<char,bool> m;

    string ans;
    cin>>ans;
    for (int i = 0; i < ans.length(); ++i) {
        m[(char)toupper(ans[i])]=true;
    }
    for (int i = 0; i < str.length(); ++i) {
        if(m.find((char)toupper(str[i]))==m.end()){
            cout<<(char)(toupper(str[i]));
            m[(char)toupper(str[i])]=true;
        }
    }

    return 0;
}
