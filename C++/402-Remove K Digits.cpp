class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> stk;
        for (int i=0; i<num.size(); i++) {
            while (!stk.empty() && k > 0 && num[stk.top()] > num[i]) {
                stk.pop();
                k--;
            }
            stk.push(i);
        }
        
        string res;

        while (!stk.empty() && k > 0) {
            k--;
            stk.pop();
        }
        
        while (!stk.empty()) {
            res += num[stk.top()];
            stk.pop();
        }
        
        while (!res.empty() && res.back() == '0') {
            res.pop_back();
        }
        
        reverse(res.begin(), res.end());
        
        return res.empty()?"0":res;
    }
};