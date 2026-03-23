class Solution {
public:
    void dfs(int idx, int end, int curr, int skipped, vector<int>& nums, unordered_map<int, int>& hmap) {
        if (idx == end) {
            if (hmap.contains(curr)) {
                hmap[curr] = min(hmap[curr], skipped);
            } else {
                hmap[curr] = skipped;
            }
            return;
        }
        // use
        dfs(idx+1, end, curr^nums[idx], skipped, nums, hmap);

        // skip
        dfs(idx+1, end, curr, skipped+1, nums, hmap);

    }
    int minRemovals(vector<int>& nums, int target) {
        int N = nums.size();
        unordered_map<int, int> hmap1, hmap2;
        
        // meet in the middle
        dfs(0, N/2, 0, 0, nums, hmap1);
        dfs(N-(N+1)/2, N, 0, 0, nums, hmap2);        
        
        int res = N+1;
        for (auto &[k, v]:hmap1) {
            if (hmap2.contains(k^target)) {
                res = min(res, v + hmap2[k^target]);
            }
        }

        return res==N+1?-1:res;
    }
};