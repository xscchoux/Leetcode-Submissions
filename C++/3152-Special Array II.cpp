class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        vector<pair<int, int>> arr;
        int start, running = 0;
        for (int i=0; i<N; i++) {
            if (i == 0) {
                start = 0;
            } else if (nums[i]%2 != nums[i-1]%2){
                running += 1;
            } else {
                arr.push_back({start, running});
                running = i;
                start = i;
            }
        }
        arr.push_back({start, running});
        vector<bool> res;
        for (auto &q:queries) {
            int u = q[0], v = q[1];
            auto it = upper_bound(begin(arr), end(arr), make_pair(q[0], INT_MAX));
            if (it == begin(arr)) {
                res.push_back(false);
                continue;
            }
            it = prev(it);
            if (it->second < v) {
                res.push_back(false);
            } else {
                res.push_back(true);
            }
        }

        return res;
    }
};