#include <iostream>
#include <algorithm>
using namespace std;
/*
 先把进制转换好，放入数组
 然后在判断回文序列
 */
int main() {
    int a,b;
    int arr[40];
    int index=0;
    scanf("%d %d",&a,&b);
    bool flag= true;
    while (a!=0){
        arr[index++]=a%b;
        a/=b;
    }
    int i=0,j=index-1;
    while(i!=j){
        if(arr[i++]!=arr[j--]){
            flag= false;
            printf("No\n");
            break;
        }
    }
    if(flag)printf("Yes\n");
    for(int k = index - 1; k >= 0; k--) {
        printf("%d", arr[k]);
        if(k != 0) printf(" ");
    }
    if(index == 0)
        printf("0");
    return 0;
}