// First AC
class Solution {
public:
    int maxSubstrings(string word) {
        int N = word.size();
        vector<deque<int>> lastPos(26);
        vector<int> dp(N+1, 0);

        for (int i=0; i<N; i++) {
            int c = word[i]-'a';
            dp[i+1] = dp[i];
            while (!lastPos[c].empty() && (i-lastPos[c].front() + 1) >= 4) {
                dp[i+1] = max(dp[i+1], dp[lastPos[c].front()] + 1);
                lastPos[c].pop_front();
            }
            lastPos[c].push_back(i);
        }

        return dp.back();
    }
};


// Much better
class Solution {
public:
    int maxSubstrings(string word) {
        int N = word.size();
        vector<int> lastPos(26, -1);
        vector<int> dp(N+1, 0);

        for (int i=0; i<N; i++) {
            dp[i+1] = dp[i];
            if (lastPos[word[i]-'a'] != -1 && (i - lastPos[word[i]-'a']+1) >= 4 ) {
                dp[i+1] = max(dp[i+1], dp[lastPos[word[i]-'a']] + 1);
            }
            if (i >= 2) {
                lastPos[word[i-2]-'a'] = i-2;
            }
        }

        return dp.back();
    }
};