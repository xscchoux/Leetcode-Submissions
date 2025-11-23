class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int, int>, int> hmap;  // {xor val, even-odd count}
        int res = 0;
        hmap[{0, 0}] = -1;
        
        int xorVal = 0, even = 0, odd = 0;

        for (int i=0; i<nums.size(); i++) {
            xorVal ^= nums[i];
            if (nums[i]%2) {
                odd++;
            } else {
                even++;
            }
            if (hmap.contains({xorVal, even-odd})) {
                res = max(res, i-hmap[{xorVal, even-odd}]);
            } else {
                hmap[{xorVal, even-odd}] = i;
            }
        }

        return res;
    }
};