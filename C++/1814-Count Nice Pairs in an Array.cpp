class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int kMod = 1e9+7;
        int res = 0;
        unordered_map<int, int> hmap;
        for (int num:nums){
            int tmp = num;
            int newNum = 0;
            while (tmp > 0){
                newNum = newNum*10 + tmp%10;
                tmp = tmp/10;
            }
            res = (res + hmap[num-newNum])%kMod;
            hmap[num-newNum] += 1;
        }
        return res;
    }
};