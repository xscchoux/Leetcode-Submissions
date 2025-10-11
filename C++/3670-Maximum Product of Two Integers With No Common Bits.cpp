// Sum over Subsets DP (SOS DP)
// https://github.com/wisdompeak/LeetCode/tree/master/Trie/3670.Maximum-Product-of-Two-Integers-With-No-Common-Bits
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int mx = *max_element(begin(nums), end(nums));
        int maxBit = log2(mx);
        int fullmask = (1<<(maxBit+1))-1;

        vector<int> dp(1<<(maxBit+1), 0);

        for (int num:nums) dp[num] = max(dp[num], num);

        // This is slower
        // for (int mask=0; mask<=fullmask; mask++) {
        //     for (int b=0; b<=maxBit; b++) {
        //         if (mask & (1<<b)) {
        //             dp[mask] = max(dp[mask], dp[mask^(1<<b)]);
        //         }
        //     }
        // }

        // SOS DP template
        for (int b=0; b<=maxBit; b++) {
            for (int mask=0; mask<=fullmask; mask++) {
                if (mask & (1<<b)) {
                    dp[mask] = max(dp[mask], dp[mask^(1<<b)]);
                }
            }
        }

        long long res = 0;

        for (int num:nums) {
            res = max(res, 1LL*num*dp[fullmask^num]);
        }

        return res;
    }
};