class Solution {
public:
    int canAssign(unordered_map<int, int> &counter, int minGroup){
        int high = minGroup + 1, low = minGroup;
        int groups = 0;

        for (auto &[k, v]:counter){
            int q = v/high, r = v%high;

            if (r == 0){
                groups += q;
            } else if (q >= low-r){
                groups += q+1;
            } else{
                return 0;
            }
        }
        return groups;
    }
    
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num:nums){
            counter[num] += 1;
        }
        
        int minFreq = nums.size();
        for (auto &[k, v]:counter){
            minFreq = min(minFreq, v);
        }

        
        for (int minGroup = minFreq; minGroup>=1; minGroup--){
            int res = canAssign(counter, minGroup);
            if (res > 0){
                return res;
            }
        }
        return 0;
    }
};