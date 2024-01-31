class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> s;
        for (char c:"+-*/") s.insert(string(1, c));
        
        for (string t:tokens) {
            if (s.find(t) != s.end()) {
                int t2 = stk.top(); stk.pop();
                int t1 = stk.top(); stk.pop();
                if (t == "+") {
                    stk.push(t1+t2);
                } else if (t == "-") {
                    stk.push(t1-t2);
                } else if (t == "*") {
                    stk.push(t1*t2);
                } else {
                    stk.push(t1/t2);
                }
            } else {
                stk.push(stoi(t));
            }
        }
        return int(stk.top());
    }
};