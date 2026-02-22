class Solution {
public:
    string maximumXor(string s, string t) {
        int cnt[2] = {};
        for (char c:t) cnt[c-'0']++;

        string res = "";
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '1') {
                if (cnt[0]) {
                    cnt[0]--;
                    res += '1';
                } else {
                    cnt[1]--;
                    res += '0';
                }
            } else {
                if (cnt[1]) {
                    cnt[1]--;
                    res += '1';
                } else {
                    cnt[0]--;
                    res += '0';
                }                
            }
        }

        return res;
    }
};