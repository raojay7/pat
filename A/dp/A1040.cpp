
#include <iostream>
using namespace std;
int dp[1010][1010];
/*
分析：dp[i][j]表示s[i]到s[j]所表示的字串是否是回文字串。只有0和1，递推方程为： 

1 当s[i] == s[j] : dp[i][j] = dp[i+1][j-1]

2 当s[i] != s[j] : dp[i][j] =0

3 边界：dp[i][i] = 1, dp[i][i+1] = (s[i] == s[i+1]) ? 1 : 0因为i、j如果从小到大的顺序来枚举的话，无法保证更新dp[i][j]的时候dp[i+1][j-1]
已经被计算过。因此不妨考虑按照字串的长度和子串的初试位置进行枚举，即第一遍将长度为3的子串的dp的值全部求出，
第二遍通过第一遍结果计算出长度为4的子串的dp的值…这样就可以避免状态无法转移的问题

首先初始化dp[i][i] = 1, dp[i][i+1]，把长度为1和2的都初始化好，然后从L = 3开始一直到 L <= len 根据动态规划的递归方程来判断
*/
int main() {
    string s;
    getline(cin, s);
    int len = s.length(), ans = 1;
    for(int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if(i < len - 1 && s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
    for(int L = 3; L <= len; L++) {
        for(int i = 0; i + L - 1 < len; i++) {
            int j = i + L -1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
