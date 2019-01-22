#include <iostream>
#include <algorithm>
using namespace std;
/*
 输入数字然后分别取余100 10输出
 可以用循环加数组写
 */
int main() {
    int str;
    scanf("%d",&str);
    int num=str/100,yushu=str%100;
    for (int i = 0; i < num; ++i) {
        printf("B");
    }
    str=yushu;
    num=str/10,yushu=str%10;
    for (int j = 0; j < num; ++j) {
        printf("S");
    }
    for (int k = 1; k <=yushu; ++k) {
        printf("%d",k);
    }

    return 0;
}