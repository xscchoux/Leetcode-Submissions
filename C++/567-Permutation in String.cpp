class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int cnt = 0, N = s1.size(), left = 0;
        int ch[26] = {0};
        for (char c:s1) ch[c-'a']++;

        for (int i=0; i<s2.size(); i++) {
            int num = s2[i]-'a';
            ch[num]--;
            if (ch[num] >= 0) cnt++;
            if (ch[num] < 0) {
                while (left <= i && i-left+1 != cnt) {
                    ch[s2[left]-'a']++;
                    if (ch[s2[left]-'a'] > 0) cnt--;
                    left++;
                }
            }
            if (cnt == N) return true;
        }

        return false;
    }
};