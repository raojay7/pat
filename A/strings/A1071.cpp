#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
using namespace std;
/*
1. 大小写不区分，所以统计之前要先s[i] = tolower(s[i]);
2. [0-9 A-Z a-z]可以简写为cctype头文件里面的一个函数isalnum
3. 必须用getline读入一长串的带空格的字符串
4. 一定要当t不为空的时候m[t]++，因为t为空也会被统计的！
5. 最重要的是如果i已经到了最后一位，不管当前位是不是字母数字，都得将当前这个t放到map里面（只要t长度不为0）
 */
int main() {
    string s, t;
    getline(cin, s);
    map<string, int> m;
    for(int i = 0; i < s.length(); i++) {
        if(isalnum(s[i])) {
            s[i] = tolower(s[i]);
            t += s[i];
        }
        if(!isalnum(s[i]) || i == s.length() - 1){
            if(t.length() != 0) m[t]++;
            t = "";
        }
    }
    int maxn = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second > maxn) {
            t = it->first;
            maxn = it->second;
        }
    }
    cout << t << " " << maxn;
    return 0;
}
