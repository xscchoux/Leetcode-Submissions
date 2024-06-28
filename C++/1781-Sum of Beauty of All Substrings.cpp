class Solution {
public:
    int beautySum(string s) {
        int N = s.size();
        int res = 0;
        for (int i=0; i<N; i++) {
            vector<int> cnt(26);
            for (int j=i; j>=0; j--) {
                cnt[s[j]-'a']++;
                int mx = 1, mn = INT_MAX;
                for (int k=0; k<26; k++) {
                    mx = max(mx, cnt[k]);
                    if (cnt[k] >= 1) {
                        mn = min(mn, cnt[k]);
                    }
                }
                res += mx-mn;
            }
        }
        return res;
    }
};