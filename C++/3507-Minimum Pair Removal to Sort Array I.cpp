class Solution {
public:
    bool nonDecreasing(vector<int>& arr) {
        for (int i=1; i<arr.size(); i++) {
            if (arr[i-1] > arr[i]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int step = 0;
        while (!nonDecreasing(nums)) {
            int idx, currMin = INT_MAX;
            for (int i=0; i<nums.size()-1; i++) {
                if (nums[i] + nums[i+1] < currMin) {
                    currMin = nums[i] + nums[i+1];
                    idx = i;
                }
            }

            step++;

            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() + idx+1);
        }

        return step;
    }
};