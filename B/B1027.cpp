#include <iostream>
using namespace std;

//找规律发现公式是2n(n+2)+1,n从0开始
//先找到满足条件的最小n
//然后得到余数
int main() {
    int N;
    char c;
    scanf("%d %c",&N,&c);
    int n=1,duoyu;
    for (; n <=N; ++n) {
        if(2*n*(n+2)+1>N){
            break;
        }
    }
    n--;//得到不大于给定数的最小值
    duoyu=N-(2*n*(n+2)+1);
    int max=2*n+1;
    //打印图案
    for (int i = 0; i < n;++i) {
        for (int j = 0; j < i; ++j) {
            printf(" ");
        }
        for (int k = max-2*i; k > 0 ; --k) {
            printf("%c",c);
        }
        printf("\n");
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = n-i; j >0; --j) {
            printf(" ");
        }
        for (int k = 0; k < i*2+1; k++) {
            printf("%c",c);
        }
        printf("\n");
    }
    printf("%d",duoyu);
    return 0;
}