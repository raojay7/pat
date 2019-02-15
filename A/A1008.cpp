#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


int main() {
    int n;
    cin>>n;
    int sum=n*5;
    int pre=0,cur;
    for (int i = 0; i < n; ++i) {
        cin>>cur;
        if(cur>pre){
            sum+=(cur-pre)*6;
        }else{
            sum+=(pre-cur)*4;
        }
        pre=cur;
    }
    cout<<sum;
    return 0;
}
