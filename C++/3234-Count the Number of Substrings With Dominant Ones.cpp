class Solution {
public:
    int numberOfSubstrings(string s) {
        // https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/solutions/5546675/o-n-sqrt-n/
        int N = s.size(), res = 0;
        for (int z=0; z+z*z<=N; z++) {
            int numZero = 0, numOne = 0, left = 0, lastStart = 0, old_res = res;
            for (int i=0; i<N; i++) {
                if (s[i] == '1') numOne++;
                else numZero++;
                while (numZero > z) {
                    if (s[left++] == '0') numZero--;
                    else numOne--;
                }
                if (numZero == z && numOne>0 && numOne >= z*z) {
                    lastStart = max(lastStart, left);
                    for (;lastStart<i && s[lastStart] == '1'; lastStart++);
                    res += 1 + min(lastStart-left, numOne-z*z);
                }
            }
            if (old_res == res) break;
        }
        return res;
    }
};