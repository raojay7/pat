#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, flag = 0;
    //从高次到低次
    while (cin >> a >> b) {
        if (b != 0) {
            if (flag == 1) cout << " ";
            cout << a * b << " " << b - 1;
            flag = 1;
        }
    }
    //如果求导之后没有非零项
    if (flag == 0) cout << "0 0";

    return 0;
}