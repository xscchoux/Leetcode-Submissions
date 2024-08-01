// binary search
class Solution {
public:
    int N;
    bool found(int length, string& s) {
        if (length == 0) return true;
        unordered_set<string> visited;
        for (int i=0; i<N-length+1; i++) {
            string substring = s.substr(i, length);
            if (visited.contains(substring)) return true;
            visited.insert(substring);
        }
        return false;
    }
    int longestRepeatingSubstring(string s) {
        this->N = s.size();
        int left = 0, right = N;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (found(mid, s)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (found(right, s)) return right;
        return left;
    }
};

// smart DP
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int N = s.size(), res = 0;
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (s[i] == s[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    res = max(res, dp[i+1][j+1]);
                }
            }
        }
        return res;
    }
};