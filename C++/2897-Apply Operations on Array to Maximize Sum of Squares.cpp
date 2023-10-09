using LL = long long;
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        // https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/discuss/4143928/Apply-Gravity-to-Bits
        // Note that nums[i] + nums[j] = (nums[i] & nums[j]) + (nums[i] | nums[j])
        vector<LL> bitArr(31, 0);
        int MOD = 1e9+7;
        
        for (int a:nums){
            for (int bit = 0; bit <= 30; bit++){
                if (a & (1<<bit)) bitArr[bit] += 1;
            }
        }
        LL res = 0;
        for (int j = 0; j < k; j++){
            LL x = 0; // form the maximum number with the available bit counts
            for (int i=0; i<bitArr.size(); i++){
                if (bitArr[i] > 0){
                    x |= (1<<i);
                    bitArr[i] -= 1;
                }
            }
            res = (res+x*x)%MOD;
        }
          
        return res;
    }
};