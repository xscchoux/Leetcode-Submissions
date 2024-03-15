class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> left(N);
        vector<int> res(N);
        int curr = 1;
        for (int i=0; i<N; i++) {
            curr *= nums[i];
            left[i] = curr;
        }
        
        curr = 1;
        for (int i= N-1; i>=0; i--) {
            if (i-1>=0) {
                res[i] = curr*left[i-1];
            } else {
                res[i] = 1*curr;
            }
            curr = curr*nums[i];
        }
        
        return res;
    }
};