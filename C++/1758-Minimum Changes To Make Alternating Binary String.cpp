class Solution {
public:
    int alternate(string& s, int num) {
        int res = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]-'0' != num) {
                res++;
            }
            num = 1-num;
        }
        return res;
    }
    int minOperations(string s) {
        return min(alternate(s, 1), alternate(s, 0));
    }
};