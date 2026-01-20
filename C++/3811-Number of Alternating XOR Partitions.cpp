// https://leetcode.com/problems/number-of-alternating-xor-partitions/solutions/7502498/simple-solution-example-detailed-explana-a60o/
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int N = nums.size(), kMod = 1e9+7;

        unordered_map<int, int> xorCnt1, xorCnt2;  // count of end points that has certain xor value and ends with target1/target2. xor value: count
        xorCnt2[0] = 1;
        int xorVal = 0;

        for (int i=0; i<N; i++) {
            xorVal = xorVal^nums[i];
            int ways1 = 0, ways2 = 0;

            if (xorCnt2.contains(xorVal^target1)) {
                ways1 = xorCnt2[xorVal^target1];
            }
            if (xorCnt1.contains(xorVal^target2)) {
                ways2 = xorCnt1[xorVal^target2];
            }

            xorCnt1[xorVal] = (xorCnt1[xorVal] + ways1)%kMod;
            xorCnt2[xorVal] = (xorCnt2[xorVal] + ways2)%kMod;

            if (i == N-1) {
                return (ways1 + ways2)%kMod;
            }
        }

        return 0;
    }
};