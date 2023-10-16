class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int maxIdx = 0, minIdx = 0;
        int maxVal = -1;
        int minVal = 1e9;
        
        for (int i = 0; i<nums.size(); i++){
            if (i >= indexDifference){
                int diffIdx = i - indexDifference;
                if (nums[diffIdx] > maxVal){
                    maxVal = nums[diffIdx];
                    maxIdx = diffIdx;
                }
                if (nums[diffIdx] < minVal){
                    minVal = nums[diffIdx];
                    minIdx = diffIdx;
                }
                if (maxVal - nums[i] >= valueDifference) return {maxIdx, i};
                if (nums[i] - minVal >= valueDifference) return {minIdx, i};
            }
        }
        return {-1, -1};
    }
};