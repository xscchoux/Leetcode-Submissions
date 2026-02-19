class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, count = 0, res = 0;
        
        for (int i=0; i<s.size(); i++) {
            if (i > 0 && s[i] != s[i-1]) {
                prev = count;
                count = 1;
            } else {
                count++;
            }
            if (prev >= count) {
                res++;
            }
        }

        return res;
    }
};