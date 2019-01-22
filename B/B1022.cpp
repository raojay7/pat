#include <iostream>
#include <string.h>
using namespace std;
/*
 设t = A + B，将每一次t % d的结果保存在int类型的数组s中，
 然后将t / d，直到 t 等于 0为止，
 此时s中保存的就是 t 在 D 进制下每一位的结果的倒序，
 最后倒序输出s数组即可
 */
int main() {
    int a,b,d;
    cin>>a>>b>>d;
    int sum=a+b;
    if(sum==0){
        cout<<0;
        return 0;
    }
    char s[100];
    int i=0;
    while(sum!=0){
        s[i++]=sum%d;
        sum/=d;
    }
    for (int j = i-1; j >=0 ; --j) {
        printf("%d",s[j]);
    }
    return 0;
}