#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

/*
 最大连续子序列和
 设左右为 leftindex=0,rightindex=n-1,tempindex=0,sum=-1,temp=0
*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int leftindex = 0, rightindex = n - 1, tempindex = 0, sum = -1, temp = 0;

    for (int j = 0; j < n; ++j) {
        cin >> v[j];
        temp = temp + v[j];
        if (temp < 0) {
            //放弃当前
            temp = 0;
            tempindex = j + 1;
        } else {
            if (temp > sum) {
                sum=temp;
                leftindex=tempindex;
                rightindex=j;
            }
        }
    }

    if(sum<0)sum=0;
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}



