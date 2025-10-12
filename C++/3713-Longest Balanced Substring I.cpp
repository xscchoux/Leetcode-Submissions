class Solution {
public:
    bool check(vector<int>& cnt) {
        int num = -1;
        for (int i=0; i<26; i++) {
            if (cnt[i] == 0) continue;
            if (num == -1) num = cnt[i];
            else {
                if (cnt[i] != num) return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int res = 0, N = s.size();

        for (int i=0; i<N; i++) {
            vector<int> cnt(26, 0);
            for (int j=i; j<N; j++) {
                cnt[s[j]-'a']++;
                if (check(cnt)) {
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};