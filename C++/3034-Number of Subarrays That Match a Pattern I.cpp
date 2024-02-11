class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = pattern.size(), n = nums.size();
        int res = 0;
        for (int i=0; i+m<n; i++) {
            bool found = true;
            for (int j=0; j < m ;j++) {
                if ((nums[i+j+1] > nums[i+j] && pattern[j] != 1) || (nums[i+j+1] == nums[i+j] && pattern[j] != 0) || (nums[i+j+1] < nums[i+j] && pattern[j] != -1)){
                    found = false;
                    break;
                }
            }
            if (found){
                res++;
            }
        }
        return res;
    }
};