class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flip = 0, N = nums.size(), op = 0;

        for (int i=0; i<N; i++) {
            if (nums[i] + flip != 1) {
                op++;
                flip = 1-flip;
            }
        }
        return op;
    }
};