// MLE
using LL = long long;
class Solution {
public:
    LL kMod = 1e9+7;
    int Nw, Nt;
    LL dfs(vector<string>& words, string& target, int i, int j, vector<vector<int>>& cnt, vector<vector<int>>& memo) {
        if (i == Nt) return 1;
        if (j == Nw) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int res = dfs(words, target, i, j+1, cnt, memo)%kMod;
        res = (res + dfs(words, target, i+1, j+1, cnt, memo)*cnt[j][target[i]-'a'])%kMod;

        return memo[i][j] = res;
    }
    int numWays(vector<string>& words, string target) {
        Nw = words[0].size();
        Nt = target.size();
        vector<vector<int>> cnt(Nw, vector<int>(26, 0));
        vector<vector<int>> memo(Nt, vector<int>(Nw, -1));

        for (int j=0; j<Nw; j++) {
            for (string word:words) {
                cnt[j][word[j]-'a']++;
            }
        }
        
        return dfs(words, target, 0, 0, cnt, memo);
    }
};




// using traditional array and lambda function
using LL = long long;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int kMod = 1e9 + 7;
        int n = words[0].size(), m = target.size();
        vector<vector<int>> cnt(n, vector<int>(26));
        for (int j=0; j<n; j++) {
            for (string& w:words) {
                cnt[j][w[j]-'a']++;
            }
        }

        int memo[m][n];
        memset(memo, -1, sizeof(memo));
        function<LL(int, int)> dfs = [&](int i, int j) -> LL {
            if (i >= m) return 1;
            if (j >= n) return 0;
            if (memo[i][j] != -1) return memo[i][j];
            int res = dfs(i, j+1);
            res = (res + dfs(i+1, j+1)*cnt[j][target[i]-'a'])%kMod;
            return memo[i][j] = res;
        };
        return dfs(0, 0);
    }
};


// bottom-up DP
using LL = long long;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int Nt = target.size(), Nw = words[0].size(), kMod = 1e9+7;
        vector<vector<int>> cnt(Nw, vector<int>(26, 0));
        
        for (auto &w:words) {
            for (int j=0; j<Nw; j++) {
                cnt[j][w[j]-'a']++;
            }
        }

        // dp[i][j] : number of ways to form target[:i] from all word[:j] in words
        vector<vector<LL>> dp(Nt+1, vector<LL>(Nw+1, 0));
        for (int k=0; k<=Nw; k++) {
            dp[0][k] = 1;          // initial value when no char in words is used
        }

        for (int i=1; i<=Nt; i++) {
            for (int j=i; j<=Nw; j++) {
                // skip all word[j-1] in words
                dp[i][j] = dp[i][j-1];
                // use all word[j-1] in words
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]*cnt[j-1][target[i-1]-'a'])%kMod;
            }
        }

        return dp[Nt][Nw];
    }
};


// Better space complexity
using LL = long long;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int Nt = target.size(), Nw = words[0].size(), kMod = 1e9+7;
        vector<vector<int>> cnt(Nw, vector<int>(26, 0));
        
        for (auto &w:words) {
            for (int j=0; j<Nw; j++) {
                cnt[j][w[j]-'a']++;
            }
        }

        vector<LL> prev(Nw+1, 1), curr(Nw+1, 0); 
        for (int i=1; i<=Nt; i++) {
            for (int j=i; j<=Nw; j++) {
                curr[j] = curr[j-1];
                curr[j] = (curr[j] + prev[j-1]*cnt[j-1][target[i-1]-'a'])%kMod;
            }
            prev = curr;
            fill(curr.begin(), curr.end(), 0);
        }

        return prev[Nw];
    }
};