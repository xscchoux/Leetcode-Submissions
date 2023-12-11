class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        int left = 0, N = nums.size(), res = 0;
        for (int i=0; i<N; i++){
            hmap[nums[i]] += 1;
            while (hmap[nums[i]] > k){
                hmap[nums[left]] -= 1;
                left++;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};