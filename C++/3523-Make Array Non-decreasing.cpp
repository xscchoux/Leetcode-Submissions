class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int mx = 0;
        int cnt = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] >= mx) {
                cnt++;
                mx = nums[i];
            }
        }

        return cnt;
    }
};