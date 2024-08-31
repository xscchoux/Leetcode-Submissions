class Solution {
public:
    string stringHash(string s, int k) {
        int N = s.size();
        string res;
        for (int i=0, curr = 0; i<N; i++) {
            curr = (curr + (s[i] - 'a'))%26;
            if ( (i+1)%k == 0) {
                res += char(curr+'a');
                curr = 0;
            }
        }

        return res;
    }
};