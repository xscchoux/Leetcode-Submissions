class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        for (int i=0; i<k; i++) hmap[nums[i]]++;
        vector<int> res = {(int)hmap.size()};

        for (int i=k; i<nums.size(); i++) {
            hmap[nums[i]]++;
            hmap[nums[i-k]]--;
            if (hmap[nums[i-k]] == 0) hmap.erase(nums[i-k]);
            res.push_back(hmap.size());
        }

        return res;
    }
};