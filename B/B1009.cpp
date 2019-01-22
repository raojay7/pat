#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
/*
 将输入的每个单词s都分别v.push(s)压入栈中，
 再输出栈顶v.top()，然后将栈顶元素弹出v.pop()，直到栈空为止
 */

int main() {
    stack<string> v;
    string s;
    while(cin>>s)v.push(s);
    cout<<v.top();
    v.pop();
    while (!v.empty()){
        cout<<" "<<v.top();
        v.pop();
    }
    return 0;
}