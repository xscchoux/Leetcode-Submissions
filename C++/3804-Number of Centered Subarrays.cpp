class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int res = 0;

        for (int i=0; i<nums.size(); i++) {
            int tot = 0;
            unordered_set<int> s;
            for (int j=i; j<nums.size(); j++) {
                tot += nums[j];
                s.insert(nums[j]);
                if (s.contains(tot)) {
                    res++;
                }
            }
        }

        return res;
    }
};