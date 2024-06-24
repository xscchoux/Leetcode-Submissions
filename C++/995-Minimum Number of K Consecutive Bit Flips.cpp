class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> dp(N, 0);
        int flip = 0, res = 0;

        for (int i=0; i<N; i++) {
            flip -= dp[i];
            if (nums[i] == flip%2) {
                if (i > N-k) return -1;
                res++;
                flip++;
                if (i+k < N) dp[i+k]++;
            }
        }

        return res;
    }
};