#include <iostream>
using namespace std;
/*
用字符串接收name和birth，
 如果当前birth >= “1814/09/06″且<= “2014/09/06″，则是有效生日，
 有效个数cnt++，
 如果birth >= maxbirth，则更新maxname和maxbirth的值；
 如果birth <= minbirth，则更新minname和minbirth的值，
 这里的max和min是指数值上的大小～最后输出cnt，minname和maxname，
 minname表示最年长的（生日的数值大小最小的），
 maxname表示最年轻的（生日的数值大小最大的）
 */


int main() {
    string name,birth,maxbirth="1814/09/06",minbirth="2014/09/06",minname,maxname;
    int cnt=0,n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>name>>birth;
        if(birth >= "1814/09/06"&&birth<= "2014/09/06"){
            cnt++;
            if(birth>=maxbirth){
                maxname=name;
                maxbirth=birth;
            }
            if(birth<=minbirth){
                minname=name;
                minbirth=birth;
            }
        }
    }
    cout<<cnt;
    if(cnt!=0)cout<<" "<<minname<<" "<<maxname;
    return 0;
}
