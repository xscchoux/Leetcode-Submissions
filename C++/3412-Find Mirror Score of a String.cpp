using LL = long long;
class Solution {
public:
    long long calculateScore(string s) {
        LL res = 0;
        int N = s.size();
        vector<vector<int>> last(26, vector<int>());
        for (int i=0; i<N; i++) {
            int mirrorIdx = 25-(s[i]-'a');
            if ( !last[mirrorIdx].empty()) {
                int idx = last[mirrorIdx].back();
                last[mirrorIdx].pop_back();
                res += i-idx;
            } else {
                last[s[i]-'a'].push_back(i);
            }
        }
        return res;
    }
};