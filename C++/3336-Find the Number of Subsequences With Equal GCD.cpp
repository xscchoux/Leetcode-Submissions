using LL = long long;
class Solution {
public:
    int N, mx, kMod=1e9+7;
    vector<vector<vector<int>>> memo;
    int dfs(vector<int>& nums, int idx, int gcd1, int gcd2) {
        if (idx == N) {
            if (gcd1 == mx+1 || gcd2 == mx+1) return 0;
            return (gcd1 == gcd2)?1:0;
        }
        if (memo[idx][gcd1][gcd2] != -1) return memo[idx][gcd1][gcd2];

        LL res = 0;
        // add nums[idx] in subsequence1
        res = (res + dfs(nums, idx+1, (gcd1==mx+1)?nums[idx]:(gcd(gcd1, nums[idx])), gcd2))%kMod;
        // add nums[idx] in subsequence2
        res = (res + dfs(nums, idx+1, gcd1, (gcd2==mx+1)?nums[idx]:(gcd(gcd2, nums[idx]))))%kMod;
        // skip nums[idx]
        res = (res + dfs(nums, idx+1, gcd1, gcd2))%kMod;

        return memo[idx][gcd1][gcd2] = res;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->N = nums.size();
        this->mx = *max_element(begin(nums), end(nums));
        memo.resize(N, vector<vector<int>>(mx+2, vector<int>(mx+2, -1)));

        return dfs(nums, 0, mx+1, mx+1);
    }
};


// iterative
class Solution {
private:
    static constexpr int kMod = 1e9+7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int N = nums.size();
        int mx = *max_element(begin(nums), end(nums));

        // dp[i][j] = ways to create seq1 with GCD i and seq2 with GCD j
        vector<vector<int>> dp(mx+1, vector<int>(mx+1, 0));
        dp[0][0] = 1;

        for (int num:nums) {
            vector<vector<int>> ndq(mx+1, vector<int>(mx+1, 0));
            for (int i=0; i<=mx; i++) {
                int gcd1 = __gcd(num, i);
                for (int j=0; j<=mx; j++) {
                    int val = dp[i][j];
                    if (val == 0) {
                        continue;
                    }
                    int gcd2 = __gcd(num, j);
                    // add num to seq1
                    ndq[gcd1][j] = (ndq[gcd1][j] + val)%kMod;
                    // add num to seq2
                    ndq[i][gcd2] = (ndq[i][gcd2] + val)%kMod;
                    // skip
                    ndq[i][j] = (ndq[i][j] + dp[i][j])%kMod;
                }
            }
            swap(dp, ndq);
        }

        long long res = 0;
        for (int g=1; g<=mx; g++) {
            res = (res + dp[g][g])%kMod;
        }

        return res;
    }
};