// First try, very slow DP but passed
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> diff;
        for (int i=0; i<s1.size(); i++){
            if (s1[i] != s2[i]) diff.push_back(i);
        }
        
        int N = diff.size();
        if (N == 0) return 0;
        if (N%2 != 0) return -1;
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX/2));
        for (int i=0; i<N; i++){
            for (int j=i+1; j<N; j++){
                dp[j][i] = 0;
            }
        }
        
        for (int length=2; length<=N; length+=2){
            for (int i=0; i<N; i++){
                int j = i+length-1;
                if (j >= diff.size()) break;
                dp[i][j] = min(dp[i][j], min(x + dp[i+1][j-1], diff[j]-diff[i]+dp[i+1][j-1]));
                for (int k=i+2; k<=j; k+=2){
                    dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j]);
                }
            }
        }
        
        return dp[0][N-1];
    }
};


// O(N^2) DP
class Solution {
public:
    int dfs(int left, int right, vector<int>& diff, vector<vector<int>>& memo, int x){
        if (left >= right) return 0;
        if (memo[left][right] != -1) return memo[left][right];
        
        int s1 = min(x, diff[left+1]-diff[left]) + dfs(left+2, right, diff, memo, x);
        int s2 = min(x, diff[right]-diff[right-1]) + dfs(left, right-2, diff, memo, x);
        int s3 = min(x, diff[right]-diff[left]) + dfs(left+1, right-1, diff, memo, x);
        int res = min(s1, min(s2, s3));
        return memo[left][right] = res;
    }
    
    int minOperations(string s1, string s2, int x) {
        vector<int> diff;
        for (int i=0; i<s1.size(); i++){
            if (s1[i] != s2[i]) diff.push_back(i);
        }
        int N = diff.size();
        if (N == 0) return 0;
        if (N%2 != 0) return -1;
        vector<vector<int>> memo(N, vector<int>(N, -1));
        
        return dfs(0, N-1, diff, memo, x);
    }
};