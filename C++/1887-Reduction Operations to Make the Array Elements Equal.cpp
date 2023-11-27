class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> hmap;
        for (int num:nums){
            hmap[num]++;
        }
        int res = 0, count = 0;
        for (auto it = hmap.end(); it != hmap.begin(); it--){
            count += it->second;
            res += count;
        }        
        return res;
    }
};