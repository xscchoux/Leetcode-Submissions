using LL = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minPos = -1, maxPos = -1, leftPos = -1;
        LL res = 0;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                leftPos = i;
            } else {
                if (nums[i] == minK) minPos = i;
                if (nums[i] == maxK) maxPos = i;
            }
            res += max(0, min(minPos, maxPos) - leftPos);
        }
        return res;
    }
};