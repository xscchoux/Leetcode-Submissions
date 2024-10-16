class Solution {
public:
    int N;
    int kMod = 1e9+7;
    int dfs(string& s, int idx, int last, int sum, vector<vector<vector<int>>>& memo) {  // 1:F, 2:W, 3:E
        if (idx == N) return (sum>0)?1:0;
        if (memo[idx][last][sum+N] != -1) return memo[idx][last][sum+N];

        int res = 0;
        char curr = s[idx];
        if (last != 1) { // put F
            res = (res + dfs(s, idx+1, 1, (curr=='E')?sum+1:(curr=='W')?sum-1:sum, memo))%kMod;
        }
        if (last != 2) { // put W
            res = (res + dfs(s, idx+1, 2, (curr=='F')?sum+1:(curr=='E')?sum-1:sum, memo))%kMod;
        }
        if (last != 3) { // put E
            res = (res + dfs(s, idx+1, 3, (curr=='W')?sum+1:(curr=='F')?sum-1:sum, memo))%kMod;
        }

        return memo[idx][last][sum+N] = res;
    }
    int countWinningSequences(string s) {
        N = s.size();
        vector<vector<vector<int>>> memo(N, vector<vector<int>>(4, vector<int>(2*N+1, -1)));
        return dfs(s, 0, 0, 0, memo);
    }
};