class Solution {
public:
    int passwordStrength(string password) {
        vector<bool> lower(26, false), upper(26, false), number(10, false);
        unordered_set<char> s;

        for (char c:password) {
            if (c>='a' && c <= 'z') {
                lower[c-'a'] = true;
            } else if (c>='A' && c<='Z') {
                upper[c-'A'] = true;
            } else if (c >= '0' && c <= '9') {
                number[c-'0'] = true;
            } else {
                if (c == '!' || c == '@' || c == '#' || c == '$') {
                    s.insert(c);
                }
            }
        }

        int res = 0;
        for (int i=0; i<26; i++) {
            if (lower[i]) res++;
            if (upper[i]) res+=2;
        }

        for (int i=0; i<10; i++) {
            if (number[i]) res+=3;
        }

        res += 5*(int)s.size();
        return res;
    }
};