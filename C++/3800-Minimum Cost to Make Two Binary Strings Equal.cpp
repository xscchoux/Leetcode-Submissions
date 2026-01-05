class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        // count mismatched 01 and 10
        int N = s.size(), mismatch01 = 0, mismatch10 = 0;
        long long res = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == '0' && t[i] == '1') {
                mismatch01++;
            } else if (s[i] == '1' && t[i] == '0') {
                mismatch10++;
            }
        }

        if (mismatch01 == 0 && mismatch10 == 0) return 0;

        // deal with 10 and 01 pairs
        int pairs = min(mismatch01, mismatch10);

        res += pairs*min(2LL*flipCost, 1LL*swapCost);

        mismatch01 -= pairs;
        mismatch10 -= pairs;

        // deal with 01's or 10's
        res += (mismatch01/2)*min(1LL*(crossCost + swapCost), 2LL*flipCost);
        res += (mismatch10/2)*min(1LL*(crossCost + swapCost), 2LL*flipCost);        

        if (mismatch01%2) {
            res += flipCost;
        }
        if (mismatch10%2) {
            res += flipCost;
        }

        return res;
    }
};