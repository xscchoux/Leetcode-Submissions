class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, vector<int>> hmap;
        for (int i=0; i<N; i++) {
            hmap[nums[i]].push_back(i);
        }

        int res = INT_MAX;
        for (auto &[k, v]:hmap) {
            if (v.size() < 3) continue;

            for (int i=2; i<v.size(); i++) {
                res = min(res, 2*(v[i]-v[i-2]));
            }
        }

        return res<INT_MAX?res:-1;
    }
};