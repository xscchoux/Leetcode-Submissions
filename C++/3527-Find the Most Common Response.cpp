class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> cnt;
        for (auto &r:responses) {
            unordered_set<string> visited;
            for (string &s:r) {
                if (visited.contains(s)) continue;
                visited.insert(s);
                cnt[s]++;
            }
        }

        int maxCnt = 0;
        string res;
        for (auto &[k, v]:cnt) {
            if (v > maxCnt) {
                res = k;
                maxCnt = v;
            } else if (v == maxCnt) {
                res = min(res, k);
            }
        }

        return res;
    }
};