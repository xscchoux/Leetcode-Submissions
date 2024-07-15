class Solution {
public:
    pair<int, int> cal(unordered_map<int, vector<int>>& graph, int val) {
        if (graph[val].empty()) return {val%10, 1};
        int res = 0;
        int path = 0;
        for (int nxt:graph[val]) {
            auto [nxtVal, pathCnt] = cal(graph, nxt);
            res += (val%10)*pathCnt + nxtVal; 
            path += pathCnt;
        }
        return {res, path};
    }
    int pathSum(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>> hmap;
        unordered_map<int, vector<int>> graph;
        int N = nums.size();

        // create the graph
        for (int num:nums) {
            string s = to_string(num);
            hmap[s[0]-'0'][s[1]-'0'-1] = num;
        }

        for (int i=0; i < N; i++) {
            string num = to_string(nums[i]);
            // find parent
            int parentR = num[0]-'0', parentC = num[1]-'0'-1;
            if (hmap.count(parentR-1) && hmap[parentR-1].count(parentC/2)) {
                graph[hmap[parentR-1][parentC/2]].push_back(nums[i]);
            }
        }

        return cal(graph, nums[0]).first;
    }
};