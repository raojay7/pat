#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

/*

*/
bool isPrim(int num) {
    if(num==1||num==2)return true;
    for (int i = 2; i <= sqrt(num); ++i) {
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main() {
    int n, p = 0, t = 0;
    cin >> n;
    int sushu[100001];
    int index=0;
    for (int i = 1; i <= n; ++i) {
        if(isPrim(i)){
            sushu[index++]=i;
        }
    }
    int cnt=0;
    for (int i = 1; i < index; ++i) {
        if(sushu[i]-sushu[i-1]==2)cnt++;
    }
    cout<<cnt;


    return 0;
}
