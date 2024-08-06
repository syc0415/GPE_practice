// Last Digit
// uva 10162
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
f（10*k+0）= 0；
f（10*k+1）= 1；
f（10*k+2）= 4，6；
f（10*k+3）= 7，3；
f（10*k+4）= 6；
f（10*k+5）= 5；
f（10*k+6）= 6；
f（10*k+7）= 3，7；
f（10*k+8）= 6，4；
f（10*k+3）= 9；
————————————————
循环节为20的倍数：(加起來)
0，1，5，2，8，3，9，2，8，7，7，8，4，7，3，8，4，1，5，4，4

5，9，6，2，7，3，6，2，1，1，2，8，1，7，2，8，5，9，8，8，9
每次循环20个之后，尾数都比上一次的多4，因此循环节为100；
取出输入的数字最后的2位（即%100）
输出 （（value % 20 + 4 * value / 20））% 10 即可
*/

int main() {
    int sum[20] = {0,1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,5,4};

    string str;
    while (cin >> str) {
        int len = str.length();
        if (len == 1 && str[0] == '0')
            break;

        int num;
        num = str[len - 1] - '0';
        if (len > 1)
            num += (str[len - 2] - '0') * 10; // 取最後兩位
        
        int digit = sum[num % 20] + 4 * (num / 20); // 要有括號
        digit %= 10;

        cout << digit << '\n';
    }

    return 0;
}