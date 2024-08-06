// Parser and evaluator]
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int calculate(string s) {
    int len = s.length();
    if (len == 0) return 0;
    stack<int> st;
    int num = 0;
    char operation = '+';
    for (int i = 0; i < len; i++) {
        char cur = s[i];
        if (iswspace(cur)){
            cout << "syntactically incorrect";
            break;
        }
        else if (isdigit(cur)){
            num = num * 10 + (cur - '0');
            continue;  
        }  
        if (!isdigit(cur) || i == len - 1){
            if (operation == '('){
                st.push('(');
            }
            if (operation == '+')
                st.push(num);
            else if (operation == '-')
                st.push(-num);
            else if (operation == '*') {
                int temp = st.top();
                st.pop();
                st.push(temp * num);
            }
            else if (operation == '/') {
                int temp = st.top();
                st.pop();
                st.push(temp / num);
            }
            else if (operation == '%'){
                int temp = st.top();
                st.pop();
                st.push(temp % num);
            }
            operation = cur;
            num = 0;
        }
    }
    int result = 0;
    while (st.size() != 0) {
        result += st.top();
        st.pop();
    }
    return result;
}



int calculate(string s) {
    int ans = 0;
    int len = s.length();
    int sign = 1; // + or -
    stack<int> st;
    int i = 0;
    while (i < len){
        if ('0' <= s[i] <= '9'){
            int num = 0;
            while (i < len && '0' <= s[i] <= '9'){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            ans += sign * num;
            continue;
        }
        else if (s[i] == '+'){
            sign = 1;
            i++;
        }
        else if (s[i] == '-'){
            sign = -1;
            i++;
        }
        else if (s[i] == '%'){
            st.
        }
        else if (s[i] == '('){
            st.push(ans);
            st.push(sign);
            //stack.append(ans)
            //stack.append(sign)
            ans = 0;
            sign = 1;
            i++;
        }
        else if (s[i] == ')'){
            sign = st.top();
            st.pop();
            int pre = st.top();
            st.pop();
            ans = pre + sign * ans;
            i++;
        }
    return ans;
}

int main(){
    string formula;
    int len = formula.length();

    



    return 0;
}
