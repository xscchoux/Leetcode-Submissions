class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];
        unordered_set<int> s(begin(nums), end(nums));

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) {
                prefixSum += nums[i];
            } else {
                break;
            }
        }

        while (s.contains(prefixSum)) {
            prefixSum++;
        }

        return prefixSum;
    }
};