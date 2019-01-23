#include <iostream>
#include <cctype>
using namespace std;
/*
 按照题目所给的方法找到相等的字符后判断即可，
 如果输出的时间不足2位数要在前面添0，即用%02d输出
 */

int main() {
    //判断相同位置的字符是否相同，一共3个while
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    char t[2];
    int pos,i=0,j=0;
    while(i<a.length()&&i<b.length()){
        if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G'){
            t[0]=a[i];
            break;
        }
        i++;
    }
    i=i+1;
    while(i<a.length()&&i<b.length()){
        if(a[i]==b[i]&&((a[i]>='A'&&a[i]<='N')||isdigit(a[i]))){
            t[1]=a[i];
            break;
        }
        i++;
    }
    while (j < c.length() && j < d.length()) {
        if (c[j] == d[j] && isalpha(c[j])) {
            pos = j;
            break;
        }
        j++;
    }
    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    int m = isdigit(t[1]) ? t[1] - '0' : t[1] - 'A' + 10;
    cout << week[t[0]-'A'];
    printf("%02d:%02d", m, pos);
    return 0;
}