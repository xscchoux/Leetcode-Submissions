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