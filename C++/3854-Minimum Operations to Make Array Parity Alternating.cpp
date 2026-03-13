class Solution {
public:
    int getAns1(int lastParity, vector<int> nums, int mx, int mn, vector<vector<int>>& dp, int mxCnt, int mnCnt) {
        int parity = lastParity;
        for (int i=nums.size()-1; i>=0; i--) {
            if (dp[parity][i+1] > dp[1-parity][i]) {
                if (nums[i] == mx) {
                    mxCnt--;
                } else if (nums[i] == mn) {
                    mnCnt--;
                }
            }
            parity = 1 - parity;
        }

        for (int i=nums.size()-1; i>=0; i--) {
            if (dp[lastParity][i+1] > dp[1-lastParity][i]) {
                if (nums[i] == mx) {
                    nums[i]--;
                } else if (nums[i] == mn) {
                    nums[i]++;
                } else {
                    if (abs(nums[i]-mx) > abs(nums[i]-mn)) {
                        nums[i]++;
                    } else if (abs(nums[i]-mx) < abs(nums[i]-mn)) {
                        nums[i]--;
                    } else {
                        if (mxCnt == 0) {
                            nums[i]--;
                        } else if (mnCnt == 0) {
                            nums[i]++;
                        } else {
                            nums[i]--;
                        }
                    }
                }
            }
            lastParity = 1 - lastParity;
        }


        return *max_element(begin(nums), end(nums)) - *min_element(begin(nums), end(nums));
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(2, vector<int>(N+1, INT_MAX));
        dp[0][0] = dp[1][0] = 0;

        for (int i=0; i<N; i++) {
            dp[1-(nums[i]&1)][i+1] = dp[nums[i]&1][i] + 1;
            dp[nums[i]&1][i+1] = dp[1-(nums[i]&1)][i];                
        }

        int mn = *min_element(begin(nums), end(nums));
        int mx = *max_element(begin(nums), end(nums));
        int mxCnt = 0, mnCnt = 0;
        for (int i=0; i<N; i++) {
            if (nums[i] == mx) mxCnt++;
            if (nums[i] == mn) mnCnt++;
        }

        int ans1 = INT_MAX;
        int minStep = min(dp[1][N], dp[0][N]);
        if (minStep == dp[1][N] && minStep == dp[0][N]) {
            ans1 = min(getAns1(0, nums, mx, mn, dp, mxCnt, mnCnt), getAns1(1, nums, mx, mn, dp, mxCnt, mnCnt));
        } else if (minStep == dp[1][N]) {
            ans1 = getAns1(1, nums, mx, mn, dp, mxCnt, mnCnt);
        } else {
            ans1 = getAns1(0, nums, mx, mn, dp, mxCnt, mnCnt);
        }

        return {minStep, ans1};
    }
};