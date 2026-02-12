class Solution {
public:
    vector<int> delayedCount(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> hmap;

        for (int i=0; i<nums.size(); i++) {
            hmap[nums[i]].push_back(i);
        }

        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            auto it = upper_bound(hmap[nums[i]].begin(), hmap[nums[i]].end(), i+k);
            res.push_back(hmap[nums[i]].end() - it);
        }

        return res;
    }
};


class Solution {
public:
    vector<int> delayedCount(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;

        for (int i=k+1; i<nums.size(); i++) {
            cnt[nums[i]]++;
        }

        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            if (!cnt.contains(nums[i])) {
                res.push_back(0);
            } else {
                res.push_back(cnt[nums[i]]);
            }

            if (i + k + 1 < nums.size()) cnt[nums[i+k+1]]--;
        }

        return res;
    }
};