#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int book[101];
int main() {
    int n;
    scanf("%d",&n);
    int num;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&num);
        book[num]++;
    }
    int m;
    scanf("%d",&m);
    int qnum;
    for (int j = 0; j < m; ++j) {
        scanf("%d",&qnum);
        if(j!=0)cout<<" ";
        printf("%d",book[qnum]);
    }


    return 0;
}
