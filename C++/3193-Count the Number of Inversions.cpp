// https://leetcode.com/problems/count-the-number-of-inversions/solutions/5353150/2d-dp-solution-with-memoization
class Solution {
public:
    int kMod;
    int dp[301][401];
    unordered_map<int, int> hmap;
    
    Solution(){
        kMod = 1e9+7;
    }

    int dfs(int ind, int conversions) {    // index, conversions needed
        if (conversions < 0) return 0;
        else if (hmap.contains(ind) && conversions != hmap[ind]) return 0;
        else if (ind == 0) return (conversions==0)?1:0;
        
        if (dp[ind][conversions] != -1) return dp[ind][conversions];

        int res = 0;
        for (int conversionAdded = 0; conversionAdded <= ind; conversionAdded++) {
            res = (res + dfs(ind-1, conversions-conversionAdded))%kMod;
        }

        return dp[ind][conversions] = res;
    }
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        memset(dp, -1, sizeof(dp));

        for (vector<int>& r:requirements) {
            int ind = r[0], cnt = r[1];
            hmap[ind] = cnt;
        }

        return dfs(n-1, hmap[n-1]);
    }
};