#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
 记录最低男的姓名，和课程号，以及最高女的课程号和姓名，同时
 设置最小值和最大值，最后判断最小值最大值是否改变来判断是否缺席
 */


int main() {
    string malename,femalename,lowid,highid;
    int min=101,max=-1;
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        string name,id;
        int score;
        char gender;
        cin>>name>>gender>>id;
        scanf("%d",&score);
        if(gender=='M'){
            if(score<min){
                min=score;
                malename=name;
                lowid=id;
            }
        }else if (gender=='F'){
            if(score>max){
                max=score;
                femalename=name;
                highid=id;
            }
        }
    }
    if(max!=-1){
        cout<<femalename<<" "<<highid<<endl;
    }else{
        printf("Absent\n");
    }
    if(min!=101){
        cout<<malename<<" "<<lowid<<endl;
    }else{
        printf("Absent\n");
    }
    if (max==-1||min==101){
        printf("NA");
    }else{
        printf("%d",(max-min));
    }

    return 0;
}
