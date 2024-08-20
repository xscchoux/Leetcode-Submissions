class Solution {
public:
    int N;
    int dfs(int ind, int M, vector<int>& piles, vector<int>& preSum, vector<vector<int>>& memo) {
        if (ind == N) return 0;
        if (memo[ind][M] != INT_MIN/2) return memo[ind][M];
        int stoneDiff = INT_MIN;

        for (int i=ind; i<=min(ind+2*M-1, N-1); i++) {
            stoneDiff = max(stoneDiff, preSum[i+1] - preSum[ind] - dfs(i+1, max(M, i-ind+1), piles, preSum, memo));
        }
        return memo[ind][M] = stoneDiff;
    }

    int stoneGameII(vector<int>& piles) {
        this->N = piles.size();
        vector<int> preSum(N+1, 0);
        for (int i=0; i<N; i++) preSum[i+1] = preSum[i] + piles[i];
        
        vector<vector<int>> memo(N, vector<int>(N+1, INT_MIN/2));
        int res = dfs(0, 1, piles, preSum, memo);
        int tot = accumulate(piles.begin(), piles.end(), 0);

        return (res+tot)/2;
    }
};