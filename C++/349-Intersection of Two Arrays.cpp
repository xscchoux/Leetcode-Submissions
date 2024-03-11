class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end()), resSet;
        for (int n:nums2) {
            if (s.count(n)){
                resSet.insert(n);
            }
        }
        
        vector<int> res(resSet.begin(), resSet.end());
        
        return res;
    }
};