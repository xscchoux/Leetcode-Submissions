class Solution {
public:
    int countSubstrings(string s, string t) {
        // O(2*M*N)
        int Ns = s.size(), Nt = t.size(), res = 0;
        for (int i=0; i<Ns; i++) {
            for (int j=0; j<Nt; j++) {
                if (s[i] != t[j]) {
                    int left = 1, right = 1;
                    while (min(i-left, j-left) >= 0 && s[i-left] == t[j-left]) {
                        left++;
                    }
                    while (i+right<Ns && j+right<Nt && s[i+right] == t[j+right]) {
                        right++;
                    }
                    res += left*right;
                }
            }
        }
        return res;
    }
};