class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> pos;     // num:positions
        int N = nums.size();

        for (int i=0; i<nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        vector<int> res;

        for (int q:queries) {
            int num = nums[q];
            if (pos[num].size() == 1) {
                res.push_back(-1);
                continue;
            }
            
            int val = INT_MAX;
            auto upperIt = upper_bound(begin(pos[num]), end(pos[num]), q);
            if (upperIt != end(pos[num])) {
                val = min(val, *upperIt - q );
            } else {
                val = min(val,  N - q + *begin(pos[num]) );
            }

            auto lowerIt = lower_bound(begin(pos[num]), end(pos[num]), q);
            if (lowerIt != begin(pos[num])) {
                val = min(val,  q - *(lowerIt-1) );
            } else {
                val = min(val, q + N - *rbegin(pos[num]) );
            }
            
            res.push_back(val);
        }

        return res;
    }
};