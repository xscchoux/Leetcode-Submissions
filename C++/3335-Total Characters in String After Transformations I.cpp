using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<LL> tot(26);
        for (char c:s) tot[c-'a']++;
        LL res = 0;
        for (int i=0; i<t; i++) {
            vector<LL> cnt(26);
            for (int k=0; k<26; k++) {
                if (k == 25) {
                    cnt[0] = (cnt[0] + tot[25])%kMod;
                    cnt[1] = (cnt[1] + tot[25])%kMod;
                } else {
                    cnt[k+1] = tot[k];
                }
            }
            tot = move(cnt);
        }

        for (int x:tot) res = (res+x)%kMod;

        return res;
    }
};


// Same logic but much faster
using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int cnt[26] = {0}, res = s.size();
        for (char c:s) cnt[c-'a']++;

        while (t > 0) {
            int tmp = cnt[0];
            for (int i=1; i<=25; i++) {
                int tmp2 = cnt[i];
                cnt[i] = tmp;
                tmp = tmp2;
            }
            cnt[0] = tmp;
            cnt[1] = (cnt[1] + tmp)%kMod;
            res = (res + tmp)%kMod;
            t--;
        }

        return res;
    }
};