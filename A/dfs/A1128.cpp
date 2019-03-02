#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
using namespace std;

//判断对角线的方法，只要看横纵坐标对应相减的绝对值是否相等就行
//皇后问题，由于题目以及给出一定不在同一行，就只需要判断前面的
//对于给出的数字，放入vector中有n个然后对于第j个数字，枚举0~j-1 进行判断
int main() {
    int k,n;
    cin>>k;
    for (int i = 0; i < k; ++i) {
        bool flag=true;
        int n;
        cin>>n;
        vector<int> v(n);
        for (int j = 0; j < n; ++j) {
            cin>>v[j];
            for (int t = 0; t < j; ++t) {
                if(abs(v[j]-v[t])==abs(j-t)||v[j]==v[t]){
                    flag=false;
                    break;
                }
            }
        }
        cout<<(flag?"YES\n":"NO\n");
    }
    return 0;
}
