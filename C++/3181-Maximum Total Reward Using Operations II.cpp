class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        // https://leetcode.com/problems/maximum-total-reward-using-operations-ii/solutions/5282181/quadratic-dp-array-vs-bitset
        bitset<50000> dp, mask;
        int maskInd = 0, N = rewardValues.size();
        dp[0] = true;

        sort(rewardValues.begin(), rewardValues.end());

        for (int i=0; i<N-1; i++) {
            while (maskInd < rewardValues[i]) {
                mask[maskInd] = true;
                maskInd++;
            }
            dp |= (dp&mask) << rewardValues[i];
        }

        for (int i=rewardValues[N-1]-1; i>=0; i--) {
            if (dp[i]) {
                return i + rewardValues[rewardValues.size()-1];
            }
        }

        return 0;
    }
};