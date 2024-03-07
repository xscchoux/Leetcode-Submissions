class Solution {
public:
    int maximumTripletValue(vector<int>& nums) {
        int N = nums.size();
        vector<int> rightGreater(N, -1);
        int currMax = -1, res = 0;
        
        for (int i=N-1; i>=0; i--) {
            rightGreater[i] = currMax;
            if (nums[i] > currMax) {
                currMax = nums[i];
            }
        }
        
        set<int> s;
        
        for (int i=0; i<N; i++) {
            if (nums[i] < rightGreater[i]) {
                auto it = s.lower_bound(nums[i]);
                if (it != s.begin()) {
                    res = max(res, *(--it) - nums[i] + rightGreater[i]);
                }
                s.insert(nums[i]);
            }
        }
        return res;
    }
};