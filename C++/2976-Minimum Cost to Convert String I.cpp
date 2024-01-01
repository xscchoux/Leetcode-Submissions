using LL = long long;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int N = original.size();
        vector<vector<LL>> dp(26, vector<LL>(26, 1e11+1));
        for (int i=0; i<N; i++){
            dp[original[i]-'a'][changed[i]-'a'] = min(dp[original[i]-'a'][changed[i]-'a'], (LL)cost[i]);
        }

        for (int i=0; i<26; i++){
            dp[i][i] = 0;
        }
        
        
        // Floyd-Warshall, this one is smart, all use 26
        for (int k=0; k<26; k++){
            for (int i=0; i<26; i++){
                for (int j=0; j<26; j++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        LL res = 0;
        for (int i=0; i<source.size(); i++){
            if (dp[source[i]-'a'][target[i]-'a'] >= 1e11+1) return -1;
            res += dp[source[i]-'a'][target[i]-'a'];
            
        }
        
        return res;
    }
};