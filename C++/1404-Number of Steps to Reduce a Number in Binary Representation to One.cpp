class Solution {
public:
    int numSteps(string s) {
        int N = s.size();
        int res = 0, carry = 0;

        for (int i=N-1; i>=1; i--) {
            if (((s[i]-'0')+carry)%2 > 0) {
                res += 2;
                carry = 1;
            } else {
                res++;
            }
        }

        if (carry) res++;

        return res;
    }
};