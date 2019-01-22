#include <iostream>
#include <algorithm>
using namespace std;
/*
 */
string s;
int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int b[11] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};
bool isTrue(){
    int sum=0;
    for (int i = 0; i < 17; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
        sum += (s[i] - '0') * a[i];
    }
    //最后一位为X要转换为10
    int temp=(s[17]=='X')?10:s[17]-'0';
    return b[sum%11]==temp;
}
int main() {
    int n;
    bool flag=true;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>s;
        if(!isTrue()){
            cout<<s<<endl;
            flag= false;
        }
    }
    if (flag){
        printf("All passed");
    }
    return 0;
}