class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int N = nums.size(), res = 0;
        unordered_map<int, int> cnt;

        for (int right = nums.size()-1; right > 0 ; right--) {
            for (int left = 0; left < right; left++) {
                cnt[nums[right]*nums[left]]++;
            }

        }

        for (auto &[k, v]:cnt) {
            if (v > 1) {
                res += 8*v*(v-1)/2; // 8*C(v, 2)
            }
        }

        return res;
    }
};