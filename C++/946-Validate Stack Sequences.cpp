class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int ind = 0;
        for (int c:pushed){
            stk.push(c);
            while (!stk.empty() && stk.top() == popped[ind]){
                ind += 1;
                stk.pop();
            }
        }
        return stk.empty();
    }
};