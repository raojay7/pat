#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
/*
 STL中map的应用
 使用arr[i] = j表示i元素在矩阵中出现了j次，
 在输入的同时比较arr当前的值是否已经超过半数，
 如果超过，就直接输出该数字并退出程序
 */
int main() {
    int m,n;
    map<int,int> arr;
    scanf("%d %d",&m,&n);
    int half=m*n/2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num;
            scanf("%d",&num);
            arr[num]++;
            if(arr[num]>half){
                printf("%d",num);
                return 0;
            }
        }
    }
    return 0;
}
