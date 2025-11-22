class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for (int num = max(101, num1); num<=num2; num++) {
            string s = to_string(num);
            for (int i=1; i<s.size()-1; i++) {
                if (s[i] > s[i-1] && s[i] > s[i+1]) {
                    res++;
                } else if (s[i] < s[i-1] && s[i] < s[i+1]) {
                    res++;
                }
            }
        }
        return res;
    }
};