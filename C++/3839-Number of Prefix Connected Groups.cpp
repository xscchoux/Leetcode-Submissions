class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto &w:words) {
            if (w.size() >= k) {
                cnt[w.substr(0, k)]++;
            }
        }

        int res = 0;
        for (auto &[_, v]:cnt) {
            if (v >= 2) {
                res++;
            }
        }

        return res;
    }
};