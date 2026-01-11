class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> cnt;
        for (auto &word:words) {
            int step = 'z' - word[0] + 1;
            for (auto &w:word) {
                w = 'a' + (w - 'a' + step)%26;
            }
            cnt[word]++;
        }

        long long res = 0;
        for (auto &[k, v]:cnt) {
            res += (long long)v*(v-1)/2;
        }

        return res;
    }
};