class Solution {
public:
    int minOperations(vector<int>& nums) {
        nums.push_back(0);
        stack<int> stk;
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            while (!stk.empty() && nums[i] <= nums[stk.top()]) {
                if (nums[i] < nums[stk.top()]) {
                    res++;
                }
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};