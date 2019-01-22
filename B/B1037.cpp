#include <iostream>
#include <algorithm>
using namespace std;
/*
 abc为应该付的钱，mnt代表实付的钱
 xyz为要找的钱，借位方案为17 29，借了就要减一
 要始终使pay>need，如果小了就替换，然后立即输出个-号
 */
int main() {
    int a,b,c,m,n,t,x,y,z;
    scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&m,&n,&t);
    //判断大小
    if(a>m||(a==m&&b>n)||(a==m&&b==n&&c>t)){
        swap(a,m);swap(b,n);swap(c,t);
        printf("-");
    }
    z = t < c ? t - c + 29 : t - c;
    n = t < c ? n - 1 : n;
    y = n < b ? n - b + 17 : n - b;
    x = n < b ? m - a - 1 : m - a;
    //如果是下面这样要换成>=不然就错了
//    z=t>c?t-c:t-c+29;
//    n=t>c?n:n-1;
//    y=n>b?n-b:n-b+17;
//    x=n>b?m-a:m-a-1;
    printf("%d.%d.%d", x, y, z);
    return 0;
}