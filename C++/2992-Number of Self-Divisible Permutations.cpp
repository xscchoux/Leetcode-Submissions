class Solution {
public:
    int N;
    int dp(int idx, int bitmask, vector<vector<int>>& memo){
        if (idx == N+1) return 1;
        if (memo[idx][bitmask] != -1) return memo[idx][bitmask];
        
        int res = 0;
        for (int num=1; num<=N; num++) {
            if ((gcd(num, idx) == 1 && (bitmask & 1<<(num-1)) == 0) ) {
                res += dp(idx+1, bitmask | 1<<(num-1), memo);
            }
        }
        return memo[idx][bitmask] = res;
    }
    int selfDivisiblePermutationCount(int n) {
        this->N = n;
        vector<vector<int>> memo(n+1, vector<int>((1<<n)-1, -1));
        return dp(1, 0, memo);
    }
};