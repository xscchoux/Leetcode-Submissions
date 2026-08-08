class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        vector<int> dp(sz1+1, 0);  // the number of characters word1[i:] matches word2


        // suffix preprocessing
        int idx2 = sz2-1;
        for (int i = sz1-1; i>=0; i--) {
            if (idx2 >= 0 && word1[i] == word2[idx2]) {
                idx2--;
                dp[i] = dp[i+1] + 1;
            } else {
                dp[i] = dp[i+1];
            }
        }

        // greedy
        idx2 = 0;
        int wild = 1;
        vector<int> res;
        for (int i=0; i<sz1; i++) {
            if (idx2 == sz2) break;
            if (word1[i] == word2[idx2]) {
                res.push_back(i);
                idx2++;
            } else if (wild == 1 && res.size() + wild + dp[i+1] >= sz2) {
                res.push_back(i);
                idx2++;
                wild--;
            }
        }

        if (res.size() < sz2) {
            return vector<int>{};
        }

        return res;
    }
};