#include <iostream>
#include <algorithm>
using namespace std;
/*
 把A和B都化为Knut的形式，
 然后相加，最后转换为Galleon.Sickle.Knut的形式
 */
int main() {
    long long a,b,c,d,e,f,g;
    scanf("%lld.%lld.%lld %lld.%lld.%lld",&a,&b,&c,&d,&e,&f);
    long long num=c+b*29+a*29*17+f+e*29+d*29*17;
    g=num/(17*29);
    num=num%(17*29);
    printf("%lld.%lld.%lld",g,num/29,num%29);
    return 0;
}