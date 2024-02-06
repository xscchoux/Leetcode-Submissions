using LL = long long;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, LL> hmap;  // number:minimum preSum
        LL preSum = 0;
        LL res = LLONG_MIN;
        for (int num:nums) {
            preSum += num;
            if (hmap.find(num-k) != hmap.end()) {
                res = max(res, preSum - hmap[num-k]);
            }
            if (hmap.find(num+k) != hmap.end()) {
                res = max(res, preSum - hmap[num+k]);
            }

            if (hmap.find(num) != hmap.end()) {
                hmap[num] = min(hmap[num], preSum-num);
            } else {
                hmap[num] = preSum-num;
            }
            
        }
        return res>LLONG_MIN?res:0;
    }
};