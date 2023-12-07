class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int N = s.size();
        int dp[N+1][26];
        for (int i=0; i<N; i++){
            for (int j=0; j<26; j++){
                dp[i+1][j] = dp[i][j] + ((s[i]-'a' == j)?1:0);   
            }
        }
        
        vector<int> res;
        
        for (vector<int> q:queries){
            int l = q[0], r = q[1];
            int count = 0;
            for (int i=0; i<26; i++){
                int diff = dp[r+1][i] - dp[l][i];
                if (diff > 0) {
                    count += diff;
                    if (diff > 1) count += diff*(diff-1)/2;
                }
            }
            res.push_back(count);
        }      
        return res;
    }
};