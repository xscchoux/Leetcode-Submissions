class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int> last;
        int kMod = 1e9+7;
        
        for (int i=0; i< nums.size(); i++){
            last[nums[i]] = i;
        }
        
        vector<int> cut;
        int lastIdx = 0;
        
        for (int i=0; i< nums.size(); i++){
            lastIdx = max(lastIdx, last[nums[i]]);
            if (i >= lastIdx) cut.push_back(i);
        }

        int res = 1;
        for (int i=1; i<cut.size(); i++){
            res = (res*2)%kMod;
        }
        // Can actually combine the two loops above        
        return res;
    }
};