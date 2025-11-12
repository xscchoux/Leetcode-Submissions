class Solution {
public:
    char kthCharacter(string s, long long k) {
        char curr = s[0];
        int cnt = 1;
        long long lastPos = -1;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ' ') {
                lastPos += 1;
                if (lastPos == k) {
                    return s[i];
                }
                cnt = 1;
                continue;
            }
            lastPos += cnt;
            if (k <= lastPos) {
                return s[i];
            }
            cnt++;
        }
        return '\0';
    }
};