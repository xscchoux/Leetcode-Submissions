class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNeg;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] >= 0) {
                nonNeg.push_back(nums[i]);
            }
        }

        if (nonNeg.size() <= 1) return nums;

        k = k%(nonNeg.size());
        rotate(nonNeg.begin(), nonNeg.begin() + k, nonNeg.end());  // left rotate

        int idx = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] >= 0) {
                nums[i] = nonNeg[idx++];
            }
        }

        return nums;
    }
};