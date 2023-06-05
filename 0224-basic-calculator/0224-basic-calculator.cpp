class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        int res = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= stk.top(); // sign before the parenthesis
                stk.pop();
                res += stk.top(); // result calculated before the parenthesis
                stk.pop();
            }
        }

        return res + (sign * num);
    }
};