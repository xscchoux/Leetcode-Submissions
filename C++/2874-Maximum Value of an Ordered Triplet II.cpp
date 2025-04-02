class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int N = nums.size(), preMax = 0, preMaxDiff = 0;
        long long res = 0;
        for (int i=0; i<N; i++) {
            res = max(res, (long long)nums[i]*preMaxDiff);
            preMaxDiff = max(preMaxDiff, preMax-nums[i]);
            preMax = max(preMax, nums[i]);
        }

        return res;
    }
};