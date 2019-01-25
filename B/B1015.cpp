#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//用结构体存储。写好cmp函数
//结构体数组vector v[4]中v[0]保存第一类考生，
// v[1]保存第二类考生……以此类推。
// 写好cmp函数很重要，cmp函数中，
// 排序先按照总分排序，然后按照德分排序，
// 最后按照才分排序……最后输出符合条件的结果
struct node {
    int num, de, cai;
};

int cmp(struct node a, struct node b) {
    if (a.de + a.cai != b.de + b.cai) {
        return (a.de + a.cai) > (b.de + b.cai);
    } else if (a.de != b.de) {
        return a.de > b.de;
    } else {
        return a.num < b.num;
    }
}

int main() {
    int n, low, high;
    scanf("%d%d%d", &n, &low, &high);
    vector<node> v[4];
    node temp;
    int total = n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &temp.num, &temp.de, &temp.cai);
        //4条规则
        if (temp.de < low || temp.cai < low) {
            total--;
        } else if (temp.de >= high && temp.cai >= high) {
            v[0].push_back(temp);
        } else if (temp.de >= high && temp.cai < high) {
            v[1].push_back(temp);
        } else if (temp.de < high && temp.cai < high && temp.cai <= temp.de) {
            v[2].push_back(temp);
        } else {
            v[3].push_back(temp);
        }
    }

    printf("%d\n", total);
//排序并输出
    for (int j = 0; j < 4; ++j) {
        sort(v[j].begin(), v[j].end(), cmp
        );
        for (int i = 0; i < v[j].size(); ++i) {
            printf("%d %d %d\n", v[j][i].num, v[j][i].de, v[j][i].cai);
        }
    }

    return 0;
}
