class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> lastPos(26, -1);
        int N = s.size();
        vector<int> dp(N+1, 0);
        int kMod = 1e9+7;
        dp[0] = 1;
        
        // dp[i]:number of distinct subsequences [0..i]
        // dp[i+1] = 2*dp[i] (pick or not pick) - (dp[last] if last != -1)
        // last is where s[i] appear before.
        //  Note that
        
        //     last s[i]           current s[i]
        
        //  not pick || pick    not pick || pick)
        //  (Pick last[i] and not pick current s[i]) & (Not pick last s[i] and pick current s[i])  <- duplicate 
        //  That's why we need to remove dp[last]
        
        for (int i=0; i<N; i++) {
            int last = lastPos[s[i]-'a'];
            dp[i+1] = 2*dp[i]%kMod;      
            if (last != -1) {
                dp[i+1] = (dp[i+1] - dp[last + 1 -1]+kMod)%kMod;
            }
            lastPos[s[i]-'a'] = i;
        }
        
        return (dp[N]-1+kMod)%kMod;
    }
};