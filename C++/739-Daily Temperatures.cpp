class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int N = temperatures.size();
        vector<int> res(N, 0);
        for (int i=0; i<temperatures.size(); i++) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                int ind = stk.top();
                stk.pop();
                res[ind] = i-ind;
            }
            stk.push(i);
        }
        return res;
    }
};