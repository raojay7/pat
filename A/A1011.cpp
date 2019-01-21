#include <iostream>
#include <vector>
using namespace std;
/*
 以三个数一组的形式读取，读取完一组后输出最大值代表的字母，
 然后同时ans累乘该最大值，最后根据公式输出结果
 */


int main() {
    char c[4]="WTL";
    double ans=1.0;
    for (int i = 0; i < 3; ++i) {
        double maxvalue=-1;
        int maxchar=0;
        for (int j = 0; j < 3; ++j) {
            double temp;
            scanf("%lf",&temp);
            if (maxvalue<temp){
                maxvalue=temp;
                maxchar=j;
            }
        }
        ans*=maxvalue;
        printf("%c ",c[maxchar]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}
