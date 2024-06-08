class Solution {
public:
    long long numberOfSubstrings(string s) {
        vector<int> cnt(26, 0);
        long long res = 0;
        for (char c:s) {
            int curr = c-'a';
            cnt[curr]++;
            res += cnt[curr];
            
        }

        return res;
    }
};