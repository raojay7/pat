#include <iostream>
#include <string.h>
using namespace std;
/*
分析：假设n = 字符串长度 + 2，因为2 * n1 + n2 = n，且要保证n2 >= n1, n1尽可能地大，分类讨论：
1. 如果n % 3 == 0，n正好被3整除，直接n1 == n2 == n3;
2. 如果n % 3 == 1，因为n2要比n1大，所以把多出来的那1个给n2
3. 如果n % 3 == 2, 就把多出来的那2个给n2
所以得到公式：n1 = n / 3，n2 = n / 3 + n % 3
把它们存储到二维字符数组中，一开始初始化字符数组为空格，然后按照u型填充进去，最后输出这个数组u
 */
int main() {
    char c[81], u[30][30];
    memset(u, ' ', sizeof(u));
    scanf("%s", c);
    int n=strlen(c)+2;
    int n1=n/3;
    int n2=n/3+n%3;
    int index=0;
    for (int i = 0; i < n1; ++i) {
        u[i][0]=c[index++];
    }
    for (int i = 1; i <=n2-2; ++i) {
        u[n1-1][i]=c[index++];
    }
    for (int i = n1-1; i >=0 ; --i) {
        u[i][n2-1]=c[index++];
    }
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            printf("%c",u[i][j]);
        }
        printf("\n");
    }
    return 0;
}