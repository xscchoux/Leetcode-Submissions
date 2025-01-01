class Solution {
public:
    int maxScore(string s) {
        int N = s.size(), one = 0, zero = 0;
        int best = INT_MIN;  // number of zeros minus number of ones
        for (int i=0; i<N-1; i++) {
            if (s[i] == '0') zero++;
            else one++;

            best = max(best, zero-one);
        }

        if (s[N-1] == '1') one++;

        return best+one;
    }
};