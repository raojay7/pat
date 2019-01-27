#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

/*
 建立int的二维数组，course[i][j] = k
 表示第i号课程上的人的一个列表，k是上这个课的学生的姓名所在的字符数组
 name[i][j]的i下标
 注意：strcmp返回的不一定是-1，0，1这几个数字，
 要返回bool变量还需要在后面添加strcmp是大于0还是小于0
 如果对字符串排序会比较耗时，可以通过对下标进行排序来减少时间
 */

char name[40001][5];
vector<int> course[2501];

bool cmp(int a,int b){
    return strcmp(name[a],name[b])<0;
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%s %d",name[i],&num);
        for (int j = 0; j < num; ++j) {
            int temp;
            scanf("%d",&temp);
            course[temp].push_back(i);
        }
    }

    for (int i = 1; i <= k; ++i) {
        printf("%d %lu\n",i,course[i].size());
        sort(course[i].begin(),course[i].end(),cmp);
        for (int j = 0; j < course[i].size(); ++j) {
            printf("%s\n",name[course[i][j]]);
        }
    }
    return 0;
}
