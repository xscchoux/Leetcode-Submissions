class Solution {
public:
    bool hdist(string a, string b){
        int N = a.size();
        int tot = 0;
        for (int i = 0; i<N; i++){
            if (a[i] != b[i]){
                tot ++;
                if (tot > 1) return false;
            }
        }
        return (tot == 1);
    }
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        int N = words.size();
        vector<int> from = vector(N, -1);
        vector<int> dp = vector(N, 1);
        int maxIdx = 0, maxLen = 1;
        
        for (int i=0; i<N; i++){
            for (int j=0; j<i; j++){
                if (words[i].size() == words[j].size() && hdist(words[i], words[j]) && groups[i] != groups[j]){
                    if (dp[i] < dp[j] + 1){
                        from[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if (dp[i] > maxLen){
                maxLen = dp[i];
                maxIdx = i;
            }
        }
        
        vector<string> res;
        
        while (true){
            res.push_back(words[maxIdx]);
            maxIdx = from[maxIdx];
            if (maxIdx == -1) break;
        }

        reverse(res.begin(), res.end());
        
        return res;
    }
};