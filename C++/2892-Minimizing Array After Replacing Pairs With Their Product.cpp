using LL = long long;
class Solution {
public:
    int minArrayLength(vector<int>& nums, int k) {
        // Greedy, put as many items in a box of volumn k as possible
        if (find(nums.begin(), nums.end(), 0) != nums.end()) return 1;
        
        LL prefix = nums[0];
        int res = 1;
        
        for (int i = 1; i < nums.size(); i++){
            if (prefix*nums[i] > k){
                prefix = nums[i];
                res += 1;
            }else{
                prefix *= nums[i];
            }
        }
        
        return res;
    }
};