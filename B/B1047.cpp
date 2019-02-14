#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main() {
    int n;
    map<int,int> m;
    cin>>n;
    string str;
    int score=0;
    for (int i = 0; i < n; ++i) {
        cin>>str>>score;
        int dui;
        string duinum="";
        for (int j = 0; j < str.length(); ++j) {
            if(str[j]=='-'){
                break;
            }
            duinum+=str[j];
        }
        dui=atoi(duinum.c_str());
        m[dui]+=score;
    }
    int duinum,max=-1;
    for(auto it=m.begin();it!=m.end();it++){
        if(max<it->second){
            duinum=it->first;
            max=it->second;
        }
    }
    cout<<duinum<<" "<<max;
    

    return 0;
}



