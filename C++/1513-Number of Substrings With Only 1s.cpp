class Solution {
public:
    int numSub(string s) {
        int kMod = 1e9+7;

        int cnt = 0, res = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '1') cnt++;
            else {
                res += (long long)cnt*(cnt+1)/2%kMod;
                cnt = 0;
            }
        }
        if (cnt > 0) {
            res += (long long)cnt*(cnt+1)/2%kMod;
        }

        return res;
    }
};