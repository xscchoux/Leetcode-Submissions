class Solution {
public:
    int minDifference(vector<int>& nums) {
        int N = nums.size();
        if (N <= 4) return 0;
        sort(nums.begin(), nums.end());
        
        int window = N - 3, mx = nums[0], mn = nums[0];
        int left = 0, res = INT_MAX;
        for (int i=0; i<N; i++) {
            mx = nums[i];
            if (i >= window-1) {
                mn = nums[i-window+1];
            }
            if (i>=window-1) res = min(res, mx-mn);
        }
        return res;
    }
};