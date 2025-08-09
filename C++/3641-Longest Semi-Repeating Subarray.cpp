class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int cnt = 0, left = 0, res = 0;
        unordered_map<int, int> hmap;
        
        for (int i=0; i<nums.size(); i++) {
            hmap[nums[i]]++;
            if (hmap[nums[i]] == 2) {
                cnt++;
            }
            while (left <= i && cnt > k) {
                hmap[nums[left]]--;
                if (hmap[nums[left]] == 1) {
                    cnt--;
                }
                left++;
            }
            res = max(res, i-left+1);
        }

        return res;
    }
};