#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <set>
using namespace std;

/*
 利用数组来模拟链表，可以通过algorithm来对链表进行反转
 应该考虑输入样例中有不在链表中的结点的情况。所以用个sum计数
 */

int main() {
    int first,n,k,temp;
    cin>>first>>n>>k;
    int data[100005],next[100005],list[100005];
    for (int i = 0; i < n; ++i) {
        cin>>temp;
        cin>>data[temp]>>next[temp];
    }
    //构造list
    int sum=0;
    while (first!=-1) {
        list[sum++] = first;
        first = next[first];
    }
    //反转
    for (int i = 0; i < (sum-sum%k); i+=k) {
        reverse(list+i,list+i+k);
    }
    for (int i = 0; i < sum-1; ++i) {
        printf("%05d %d %05d\n",list[i],data[list[i]],list[i+1]);
    }
    printf("%05d %d -1",list[sum-1],data[list[sum-1]]);
    return 0;
}
