class Solution {
public:
    int mostExpensiveItem(int primeOne, int primeTwo) {
        int limit = primeOne*primeTwo;
        vector<int> dp(limit, false);
        dp[0] = true;
        
        for (int num=1; num<limit; num++){
            if (num >= primeOne) dp[num] |= dp[num-primeOne];
            if (!dp[num] && num >= primeTwo) dp[num] |= dp[num-primeTwo];
        }
        for (int num = limit-1; num>=0; num--){
            if (!dp[num]) return num;
        }
        return 0;
    }
};