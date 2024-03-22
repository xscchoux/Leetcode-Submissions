// backtraking
// https://leetcode.com/problems/number-of-squareful-arrays/discuss/238562/C%2B%2BPython-Backtracking
class Solution {
public:
    unordered_map<int, int> count;
    unordered_map<int, unordered_set<int>> matched;
    int numSquarefulPerms(vector<int>& nums) {
        int res = 0;
        for (int num:nums) count[num]++;
        for (auto &a:count) {
            for (auto &b:count) {
                int e1 = a.first, e2 = b.first, e = sqrt(e1 + e2); 
                if (e*e == e1+e2) {
                    matched[e1].insert(e2);
                    matched[e2].insert(e1);
                }
            }
        }
        
        for (auto &kv:count) {
            res += dfs(kv.first, nums.size()-1);
        }
        
        return res;
    }
    
    int dfs(int num, int remain) {
        if (remain == 0) return 1;
        int ans = 0;
        count[num]--;
        for (int nxt:matched[num]) {
            if (count[nxt] > 0) {
                ans += dfs(nxt, remain-1);
            }
        }
        count[num]++;
        return ans;
    }
};