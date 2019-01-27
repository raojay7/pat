#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 1.写好结构体
 2.比较函数
 3.输入
 4.初始化
 5.计算total与passnum
 6.排序输出
 */
struct  NODE{
    int rank,id,total=0;
    vector<int> score;
    bool isshown=false;
    int passnum=0;
};
int cmp(struct NODE a, struct NODE b) {
    if(a.total!=b.total){
        return a.total>b.total;
    }else if(a.passnum!=b.passnum){
        return a.passnum>b.passnum;
    }else{
        return a.id<b.id;
    }
}

int main() {
    int N,K,M,id,num,score;
    scanf("%d %d %d",&N,&K,&M);
    vector<NODE> v(N+1);
    for (int i = 1; i <= N; ++i) {
        v[i].score.resize(K+1,-1);
    }
    vector<int> full(K+1);
    for (int i = 1; i <= K; ++i) {
        scanf("%d",&full[i]);
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d",&id,&num,&score);
        v[id].id=id;
        v[id].score[num]=max(v[id].score[num],score);
        if(score!=-1){
            //更新状态为提交成功
            v[id].isshown=true;
        } else if(v[id].score[num]==-1)//已经提交，但是编译错误
        {
            v[id].score[num]=-2;
        }
    }
    
    
    //计算total与passnum
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            if(v[i].score[j]!=-1&&v[i].score[j]!=-2){
                v[i].total+=v[i].score[j];
            }
            if (v[i].score[j]==full[j]){
                v[i].passnum++;
            }
        }
        
    }

    sort(v.begin()+1,v.end(),cmp);

    for (int i = 1; i <= N ; ++i) {
        v[i].rank=i;
        //并列
        if(i != 1 && v[i].total == v[i - 1].total)v[i].rank = v[i - 1].rank;
    }

    //输出
    for (int i = 1; i <= N; ++i) {
        if (v[i].isshown){
            printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
            for(int j = 1; j <= K; j++) {
                if(v[i].score[j] != -1 && v[i].score[j] != -2)
                    printf(" %d", v[i].score[j]);
                else if(v[i].score[j] == -1)
                    printf(" -");
                else
                    printf(" 0");
            }
            printf("\n");
        }
    }
    return 0;
}
