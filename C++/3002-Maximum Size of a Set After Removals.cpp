class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> common;
        
        for (int x:s1) {
            if (s2.find(x) != s2.end()){
                common.insert(x);
            }
        }
        int c = common.size();

        return min(N, min(N/2, (int)s1.size()-c) + min(N/2, (int)s2.size()-c) + c );
    }
};