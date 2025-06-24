class Solution {
private:
    int swapCnt[26][26];
public:
    int countOp(string& s1, string& s2) {  // count all replace and swap operations
        int N = s1.size(), res = 0;
        memset(swapCnt, 0, sizeof(swapCnt));
        
        for (int i=0; i<N; i++) {
            swapCnt[s1[i]-'a'][s2[i]-'a']++;
        }

        for (int i=0; i<26; i++) {
            for (int j=i+1; j<26; j++) {
                int common = min(swapCnt[i][j], swapCnt[j][i]);
                swapCnt[i][j] -= common;
                swapCnt[j][i] -= common;
                res += common + max(swapCnt[i][j], swapCnt[j][i]);
            }
        }

        return res;
    }

    int minOperations(string word1, string word2) {
        int N = word1.size();
        vector<int> dp(N, INT_MAX/2);  // operatios to make word1[0:i] == word2[0:i] 

        for (int i=0; i<N; i++) {   // j: start index, i: end index
            for (int j=0; j<=i; j++) {
                string s1 = word1.substr(j, i-j+1), s2 = word2.substr(j, i-j+1);
                dp[i] = min(dp[i], (j==0?0:dp[j-1]) + countOp(s1, s2));

                string reversed_s1 = s1;
                reverse(begin(reversed_s1), end(reversed_s1));
                dp[i] = min(dp[i], (j==0?0:dp[j-1]) + countOp(reversed_s1, s2) + 1);   // +1 because of reverse operation
            }
        }

        return dp.back();
    }
};