#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
/*
 首先将数列从小到大排序，设当前结果为result = 0，
 当前最长长度为temp = 0；从i = 0～n，j从i + result到n，
 【因为是为了找最大的result，所以下一次j只要从i的result个后面开始找就行了】
 每次计算temp若大于result则更新result，最后输出result的值
*/

 int main() {
    int n;
    long long p;
    scanf("%d%lld",&n,&p);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int res=0,temp=0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+res; j < n; ++j) {
            if (v[j] <= v[i] * p) {
                temp = j - i + 1;
                if (temp > res)
                    res = temp;
            } else {
                break;
            }
        }
    }
    cout<<res;

    return 0;
}



