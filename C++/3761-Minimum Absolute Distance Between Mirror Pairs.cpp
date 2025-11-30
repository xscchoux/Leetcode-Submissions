class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int res = INT_MAX, N = nums.size();
        unordered_map<int, int> hmap;
        
        for (int i=0; i<N; i++) {
            if (hmap.contains(nums[i])) {
                res = min(res, i-hmap[nums[i]]);
            }

            int reversed = 0, tmp = nums[i];
            while (tmp > 0) {
                reversed = reversed*10 + tmp%10;
                tmp = tmp/10;
            }

            hmap[reversed] = i;
        }

        return res < INT_MAX?res:-1;
    }
};