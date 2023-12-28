class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        vector<int> dp(N+1, 0);
        dp[0] = 1;
        for (int i=0; i<N; i++){
            if (i > 0 && 10 <= stoi(s.substr(i-1, 2)) && stoi(s.substr(i-1, 2)) <= 26){
                dp[i+1] += dp[i-1];
            }
            if (s[i] <= '9' && s[i] > '0'){
                dp[i+1] += dp[i];
            }
        }
        return dp[dp.size()-1];
    }
};