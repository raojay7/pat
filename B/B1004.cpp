#include <iostream>

using namespace std;
const int maxN=1001;
/*
maxname和maxnum保存成绩最高的学生的姓名和学号，
 minname和minnum保存成绩最低的学生的姓名和学号，
 max和min保存当前的最高分和最低分，因为成绩区间为0-100，
 所以初始化时先令max = -1，min = 101。
 遍历所有数据，如果当前学生数据的分数比最大值大，那么更新max的值，
 并将他的姓名学号保存在maxname和maxnum中；
 如果当前学生数据的分数比最小值小，那么更新min的值，
 并将他的姓名学号保存在minname和minnum中。
 最后输出maxname、maxnum、minname和minnum～
 */


int main() {
    string maxname,maxnum,minname,minnum;
    int n,max=-1,min=101,score;
    string name,num;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>name>>num>>score;
        if (score>max){
            max=score;
            maxname=name;
            maxnum=num;
        }
        if(score<min){
            min=score;
            minname=name;
            minnum=num;
        }
    }
    cout<<maxname<<" "<<maxnum<<endl<<minname<<" "<<minnum;
    return 0;
}
