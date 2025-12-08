class Solution {
public:
    int maxSameLengthRuns(string s) {
        unordered_map<int, int> cnt; // length:count
        int length = 0, res = 0;
        for (int i=0; i<s.size(); i++) {
            if (i > 0 && s[i] != s[i-1]) {
                cnt[length]++;
                res = max(res, cnt[length]);
                length = 1;
            } else {
                length++;
            }
        }

        return max(res, cnt[length]+1);
    }
};