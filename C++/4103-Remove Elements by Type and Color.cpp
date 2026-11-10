// array<int, int, int>   {type, color, count}
class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        // stack
        int N = types.size();
        stack<array<int, 3>> stk;
        for (int i=0; i<N; i++) {
            if (!stk.empty() && stk.top()[0] == types[i] && stk.top()[1] == colors[i]) {
                stk.top()[2] += 1;
            } else {
                stk.push({types[i], colors[i], 1});
            }
            if (stk.top()[2] == groupSize[types[i]]) {
                stk.pop();
            }
        }

        return stk.empty();
    }
};