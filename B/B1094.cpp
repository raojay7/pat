#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <climits>
#include <string>
using namespace std;

bool isprim(int num){
    if(num<=1)return false;
    if(num==2)return true;
    for (int i = 2; i*i <=num ; ++i) {
        if(num%i==0)return false;
    }
    return true;
}
int main() {
    int l,k;
    cin>>l>>k;
    string s;
    cin>>s;
    for (int i = 0; i <= l-k; ++i) {
        string t=s.substr(i,k);
        int num=stoi(t);
        if(isprim(num)){
            cout<<t;
            return 0;
        }
    }
    cout<<"404\n";
    return 0;
}
