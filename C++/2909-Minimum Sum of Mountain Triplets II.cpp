class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int res = 1e9;
        int N = nums.size();
        vector<int> left = vector(N, 0);
        left[0] = nums[0];
        
        for (int i=1; i<N; i++){
            left[i] = min(left[i-1], nums[i]);
        }
        
        int rightMin = nums[N-1];

        for (int i = N-2; i>=1; i--){
            if (nums[i] > left[i-1] && nums[i] > rightMin){
                res = min(res, left[i-1]+nums[i]+rightMin);
            }
            rightMin = min(rightMin, nums[i]);
        }
        
        return (res<1e9)?res:-1;
    }
};