class Solution {
public:
    int dfs(int idx, vector<int>& nums1, vector<int>& nums2, int swapped, vector<vector<int>>& dp) {
        if (idx == nums1.size()) return 0;
        if (dp[idx][swapped] != -1) return dp[idx][swapped];

        int prev1 = nums1[idx-1], prev2 = nums2[idx-1];

        if (swapped) { // if nums1[idx-1] and nums2[idx-1] swapped
            swap(prev1, prev2);  
        }

        int res = INT_MAX;
        // no swap
        if (nums1[idx] > prev1 && nums2[idx] > prev2) {
            res = min(res, dfs(idx+1, nums1, nums2, 0, dp));
        }

        // swap
        if (nums2[idx] > prev1 && nums1[idx] > prev2) {
            res = min(res, 1 + dfs(idx+1, nums1, nums2, 1, dp));
        }

        return dp[idx][swapped] = res;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>> dp(nums1.size()+1, vector<int>(2, -1));

        return dfs(1, nums1, nums2, 0, dp);
    }
};