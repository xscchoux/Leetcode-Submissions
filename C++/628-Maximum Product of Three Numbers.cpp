class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int N = nums.size();
        sort(begin(nums), end(nums));

        return max({nums[N-1]*nums[N-2]*nums[N-3], nums[N-1]*nums[0]*nums[1]});

    }
};