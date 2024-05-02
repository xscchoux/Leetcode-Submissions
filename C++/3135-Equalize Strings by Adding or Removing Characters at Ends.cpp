class Solution {
public:
    int minOperations(string initial, string target) {
        if (initial == target) return 0;
        // get longest common substring
        int Ni = initial.size(), Nt = target.size();
        vector<vector<int>> dp(Ni+1, vector<int>(Nt+1, 0));
        int res = 0;
        for (int i=0; i<Ni; i++) {
            for (int j=0; j<Nt; j++) {
                if (initial[i] == target[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    res = max(res, dp[i+1][j+1]);
                }
            }
        }

        return Ni + Nt - 2*res;
    }
};