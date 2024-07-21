class Solution {
public:
    int maxOperations(string s) {
        int N = s.size(), cnt = 0, res = 0;

        for (int i=0; i<N; i++) {
            if (s[i] == '1') {
                if (i > 0 && s[i-1] == '0') res += cnt;
                cnt++;
            }
        }

        if (s[N-1] != '1') res += cnt;

        return res;
    }
};