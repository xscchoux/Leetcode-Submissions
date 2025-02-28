// O(m*n*min(m, n)), MLE, storing full strings in the table is much more memory-intensive than in Java and Python
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int N1 = str1.size(), N2 = str2.size();
        vector<vector<string>> dp(N1+1, vector<string>(N2+1, ""));

        for (int i=1; i<=N1; i++) {
            for (int j=1; j<=N2; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + str1[i-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j], [](const string& a, const string& b){
                        return a.size() < b.size();
                    });
                }
            }
        }

        string lcs = dp[N1][N2];    // longest common subsequence
        
        int idx1 = 0, idx2 = 0;
        string res = "";
        for (char c:lcs) {
            while (str1[idx1] != c) {
                res += str1[idx1];
                idx1++;
            }
            while (str2[idx2] != c) {
                res += str2[idx2];
                idx2++;
            }
            res.push_back(c);
            idx1++; idx2++;
        }

        return res + str1.substr(idx1) + str2.substr(idx2);
    }
};


// use less memory, barely pass
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int N1 = str1.size(), N2 = str2.size();
        vector<string> prev(N2+1, "");

        for (int i=1; i<=N1; i++) {
            vector<string> curr(N2+1, "");
            for (int j=1; j<=N2; j++) {
                if (str1[i-1] == str2[j-1]) {
                    curr[j] = prev[j-1] + str1[i-1];
                } else {
                    curr[j] = max(curr[j-1], prev[j], [](const string& a, const string& b){
                        return a.size() < b.size();
                    });
                }
            }
            prev = curr;
        }

        string lcs = prev[N2];    // longest common subsequence
        
        int idx1 = 0, idx2 = 0;
        string res = "";
        for (char c:lcs) {
            while (str1[idx1] != c) {
                res += str1[idx1];
                idx1++;
            }
            while (str2[idx2] != c) {
                res += str2[idx2];
                idx2++;
            }
            res.push_back(c);
            idx1++; idx2++;
        }

        return res + str1.substr(idx1) + str2.substr(idx2);
    }
};

// O(m*n)
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int N1 = str1.size(), N2 = str2.size();
        vector<vector<int>> dp(N1+1, vector<int>(N2+1, 0));
        for (int i=0; i<N1; i++) {
            for (int j=0; j<N2; j++) {
                if (str1[i] == str2[j]) {
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        string s = "";
        int idx1 = N1, idx2 = N2;

        while (idx1 > 0 && idx2 > 0) {
            if (dp[idx1][idx2] == dp[idx1-1][idx2]) {
                s += str1[idx1-1]; idx1--;
            } else if (dp[idx1][idx2] == dp[idx1][idx2-1]) {
                s += str2[idx2-1]; idx2--;
            } else {
                s += str1[idx1-1];
                idx1--; idx2--;
            }
        }

        return str1.substr(0, idx1) + str2.substr(0, idx2) + string(s.rbegin(), s.rend());
    }
};