class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N = words.size();
        vector<int> preSum(N+1);
        for (int i=0; i<N; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                preSum[i+1] = preSum[i]+1;
            } else {
                preSum[i+1] = preSum[i];
            }
        }
        vector<int> res;
        for (auto &q:queries) {
            int u = q[0], v = q[1];
            res.push_back(preSum[v+1]-preSum[u]);
        }
        return res;
    }
};