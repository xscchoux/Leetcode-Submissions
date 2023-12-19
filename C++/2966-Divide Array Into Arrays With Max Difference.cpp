class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int N = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i=2; i<N; i+=3){
            if (nums[i] - nums[i-2] > k){
                return {};
            }
            res.push_back({nums[i-2], nums[i-1], nums[i]});
        }

        return res;
    }
};