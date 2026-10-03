class Solution {
public:
    int longestValidParentheses(string s) {
        int N = s.size();
        stack<int> stk;
        stk.push(-1);
        int res = 0;

        // stk keeps track of the last position where there's no invalid parentheses
        
        for (int i=0; i<N; i++) {
            if (s[i] == ')') {
                if (stk.top() != -1 && s[stk.top()] == '(') {
                    stk.pop();
                    res = max(res, i-stk.top());
                } else {
                    stk.push(i);
                }
            } else {
                stk.push(i);
            }
        }

        return res;
    }
};