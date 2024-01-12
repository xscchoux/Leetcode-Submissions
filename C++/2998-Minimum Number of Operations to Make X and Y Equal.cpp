class Solution {
public:
    int dp(int x, int y, vector<int>& memo) {
        if (x <= y) return y - x;
        if (memo[x] != -1) return memo[x];
        
        int res = x - y;
        res = min(res, dp(x/5, y, memo) + 1 + x%5 );
        res = min(res, dp(x/5+1, y, memo) + 1 + 5-x%5 );
        res = min(res, dp(x/11, y, memo) + 1 + x%11 );
        res = min(res, dp(x/11+1, y, memo) + 1 + 11-x%11 );
        
        return memo[x] = res;
    }
    
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int> memo(max(x, y)+1, -1);
        
        return dp(x, y, memo);
    }
};