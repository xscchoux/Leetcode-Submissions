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


// Redo. A faster approach
using PII = pair<int, int>;
class Solution {
public:
    pair<int, int> cal(int depth, int pos, unordered_map<int, int>& lookup) {
        int tot = 0;
        int depthPos = depth*10 + pos;
        int nxtDepthPos1 = (depth+1)*10 + 2*pos-1, nxtDepthPos2 = (depth+1)*10 + 2*pos;
        int cnt = 0;

        if (lookup.contains(nxtDepthPos1)) {
            const auto& [branches, val] = cal(depth+1, 2*pos-1, lookup);
            cnt += branches;
            tot += val;
        }
        if (lookup.contains(nxtDepthPos2)) {
            const auto& [branches, val] = cal(depth+1, 2*pos, lookup);
            cnt += branches;
            tot += val;
        }

        cnt = cnt==0?1:cnt;

        tot += lookup[depthPos]*cnt;
        return {cnt, tot};
    }
    int pathSum(vector<int>& nums) {
        unordered_map<int, int> lookup;
        for (int num:nums) {
            int v = num%10, depthPos = num/10;
            lookup[depthPos] = v;
        }

        return cal(1, 1, lookup).second;
    }
};