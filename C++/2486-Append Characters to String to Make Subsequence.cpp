class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0, j=0;
        for (int i=0, N=s.size(); i<N; i++) {
            if (s[i] == t[j]) j++;
        }
        return t.size() - j;
    }
};