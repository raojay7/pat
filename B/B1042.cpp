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

    string s1;
    map<char,int> m;
    getline(cin,s1);
    for (int i = 0; i < s1.length(); ++i) {
        if(isalpha(s1[i]))m[(char)tolower(s1[i])]++;
    }

    char c;
    int max=-1;
    for(auto it=m.begin();it!=m.end();it++){
        if(max<it->second){
            c=it->first;
            max=it->second;
        }
    }
    cout<<c<<" "<<max;
    return 0;
}



