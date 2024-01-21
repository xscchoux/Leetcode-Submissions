class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        for (int num:nums) {
            if (num%mn != 0) return 1;  // can create a number smaller than current minimum
        }
        
        double cnt = count(nums.begin(), nums.end(), mn);
        return ceil(cnt/2);
    }
};