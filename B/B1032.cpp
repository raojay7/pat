#include <iostream>
#include <vector>
using namespace std;
/*
 用数组a保存每个学校的编号对应的总分，
 在输入时将每一个分数score累加到学校编号num对应的a[num]中，
 然后遍历整个数组，将总分最高的学校编号保存在变量 t 中，
 将最高总分保存在max中，最后输出t和max的值
 */


int main() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    int num,score;
    for (int i = 1; i <=n; ++i) {
        cin>>num>>score;
        a[num]+=score;
    }
    int max=-1,t=-1;
    for (int j = 1; j <=n; ++j) {
        if (a[j]>max){
            max=a[j];
            t=j;
        }
    }
    cout<<t<<" "<<max;
    return 0;
}
