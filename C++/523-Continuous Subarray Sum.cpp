class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        hmap[0] = -1;
        int running = 0, N = nums.size();
        
        for (int i=0; i<N; i++) {
            running += nums[i];
            running%=k;
            if (hmap.contains(running) && i-hmap[running] >= 2) {
                return true;
            }
            if (!hmap.contains(running)) {
                hmap[running] = i;
            }
        }
        return false;
    }
};