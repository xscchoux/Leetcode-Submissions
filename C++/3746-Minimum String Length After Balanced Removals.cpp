class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char> stk;

        for (char c:s) {
            if (!stk.empty() && c != stk.top()) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }

        return stk.size();
    }
};