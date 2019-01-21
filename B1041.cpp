#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxN=1001;

struct Student{
    long long id;
    int examSeat;
}student[maxN];


int main() {
    int n,m;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        long long id;
        int examSeat,seat;
        scanf("%lld %d %d",&id,&seat,&examSeat);
        student[seat].id=id;
        student[seat].examSeat=examSeat;
    }//输入

    //查询
    scanf("%d",&m);
    for (int j = 0; j < m; ++j) {
        int find;
        scanf("%d",&find);
        printf("%lld %d\n",student[find].id,student[find].examSeat);
    }
    return 0;
}
