using LL = long long;
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int N = nums.size();
        vector<LL> res(k, 0);
        vector<LL> dp(k, 0);

        for (int num:nums) {
            vector<LL> newDP(k, 0);
            newDP[num%k]++;
            for (int kk=0; kk<k; kk++) {
                if (dp[kk] > 0) {
                    newDP[((num%k)*kk)%k] += dp[kk];
                }
            }
            for (int kk=0; kk<k; kk++) res[kk] += newDP[kk];
            dp = newDP;
        }

        return res;
    }
};