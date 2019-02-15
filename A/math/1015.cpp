#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
/*
 判断输入是否为负数，判断n是否为素数，把n转换为d进制再反过来转换为10进制，判断是否为素数
 */

bool isPrim(int num){
    if(num==1)return false;
    if(num==2)return true;
    for (int i = 2; i <= sqrt(num); ++i) {
        if(num%i==0)return false;
    }
    return true;
}
int main() {
    int n,d;
    while(scanf("%d",&n)!=EOF){
        if(n < 0)break;
        scanf("%d",&d);
        if(!isPrim(n)){
            printf("No\n");
            continue;
        }
        //convert
        int len=0,arr[100];
        do{
            arr[len++]=n%d;
            n=n/d;
        }while(n!=0);
        for (int i = 0; i < len; ++i) {
            n=n*d+arr[i];
        }
        if(isPrim(n)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
