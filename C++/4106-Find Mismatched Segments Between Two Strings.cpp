class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int N = s1.size(), idx = 0;
        vector<vector<string>> res;

        while (idx < N) {
            if (s1[idx] != s2[idx]) {
                int start = idx;
                while (s1[idx] != s2[idx]) {
                    idx++;
                }
                string sub1 = s1.substr(start, idx-start);
                string sub2 = s2.substr(start, idx-start);
                res.push_back({sub1, sub2});
            } else {
                idx++;
            }
        }

        return res;
    }
};