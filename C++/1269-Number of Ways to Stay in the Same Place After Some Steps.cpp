class Solution {
public:
    int steps;
    long kMod = 1e9 + 7;
    int arrLen;
    vector<vector<int>> memo;
    
    int dp(int pos, int step){
        if (step == steps){
            if (pos == 0) return 1;
            else return 0;
        }
        if (memo[pos][step] != -1) return memo[pos][step];
        
        // stay
        int ways = dp(pos, step+1);
        // left
        if (pos > 0)
            ways = (ways + dp(pos-1, step+1))%kMod;
        // right
        if (pos < arrLen - 1){
            ways = (ways + dp(pos+1, step+1))%kMod;
        }
        
        memo[pos][step] = ways;
        return ways;
    }
    
    int numWays(int steps, int arrLen) {
        this->arrLen = min(arrLen, steps);
        memo = vector(this->arrLen, vector(steps+1, -1));   // using this->memo is also OK
        this->steps = steps;
        return dp(0, 0);
    }
};