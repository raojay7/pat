#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
//要一行一行读入
char chs[6]={'P','A','T','e','s','t'};
int mp[6];//默认为PATest
int main() {
    string s1;
    cin>>s1;
    int cnt=0;
    for (int i = 0; i < s1.length(); ++i) {
        if(s1[i]=='P'){
            mp[0]++;
            cnt++;
        }else if(s1[i]=='A'){
            mp[1]++;
            cnt++;

        }else if(s1[i]=='T'){
            mp[2]++;
            cnt++;

        }else if(s1[i]=='e'){
            mp[3]++;
            cnt++;

        }else if(s1[i]=='s'){
            mp[4]++;
            cnt++;

        }else if(s1[i]=='t'){
            mp[5]++;
            cnt++;

        }
    }
    while(cnt>0){
        for (int i = 0; i < 6; ++i) {
            if(mp[i]!=0){
                cout<<chs[i];
                mp[i]--;
                cnt--;
            }
        }
    }
    return 0;
}



