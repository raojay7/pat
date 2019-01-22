#include <iostream>
#include <algorithm>
using namespace std;
/*
因为0~168的十进制转换为13进制不会超过两位数，
所以这个两位数为(num / 13)(num % 13)构成的数字
 */
int main() {
    char c[14]={"0123456789ABC"};
    printf("#");
    for (int i = 0; i < 3; ++i) {
        int a;
        scanf("%d",&a);
        printf("%c%c",c[a/13],c[a%13]);
    }
    return 0;
}