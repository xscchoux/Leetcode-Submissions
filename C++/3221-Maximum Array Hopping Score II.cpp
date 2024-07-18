class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int N = nums.size();
        int mx = -1;
        long long res = 0;
        for (int i=N-1; i>0; i--) {
            if (nums[i] < mx) nums[i] = mx;
            else mx = nums[i];
            res += nums[i];
        }

        return res;
    }
};