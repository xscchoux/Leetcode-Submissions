class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int N = nums.size();
        
        // check if nums is sorted
        bool sorted = true;
        for (int i=0; i<N; i++) {
            if (nums[i] != i) {
                sorted = false;
                break;
            }
        }

        if (sorted) return 0;

        int common = -1;
        for (int i=0; i<N; i++) {
            if (nums[i] == i) continue;
            if (common == -1) {
                common = nums[i]&i;
            } else {
                common = common & (nums[i]&i);
            }
            if (common == 0) return 0;
        }

        return common;
    }
};