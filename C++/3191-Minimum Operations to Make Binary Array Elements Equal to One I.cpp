class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        int op = 0;
        for (int i=0; i<N-2; i++) {
            if (nums[i] == 0) {
                nums[i+1] = !nums[i+1];
                nums[i+2] = !nums[i+2];
                op++;
            }
        }

        return (nums[N-2]&nums[N-1] == 1)?op:-1;
    }
};