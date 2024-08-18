class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int count = 0, N = nums.size();
        vector<int> res;
        for (int i=0; i<N; i++) {
            if (i > 0 && nums[i-1] + 1 == nums[i]) {
                count++;
            } else {
                count=1;
            }
            if (i+1 >= k) {
                res.push_back(count>=k?nums[i]:-1);
            }
        }
        return res;
    }
};