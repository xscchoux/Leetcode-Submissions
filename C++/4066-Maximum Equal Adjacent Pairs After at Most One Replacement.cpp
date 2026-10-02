class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int N = nums.size();
        int length = 0;
        map<pair<int, int>, int> unequal;

        for (int i=1; i<N; i++) {
            if (nums[i] == nums[i-1]) {
                length++;
            } else {
                unequal[{min(nums[i], nums[i-1]), max(nums[i], nums[i-1])}]++;
            }
        }

        int mxUnequal = 0;
        for (auto &[k, v]:unequal) {
            mxUnequal = max(mxUnequal, v);
        }

        return length + mxUnequal;
    }
};