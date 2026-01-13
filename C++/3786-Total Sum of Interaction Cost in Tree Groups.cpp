// First AC, very slow
class Solution {
public:
    long long res = 0;
    tuple<unordered_map<int, int>, unordered_map<int, long long>> dfs(int curr, int parent, vector<vector<int>>& graph, vector<int>& group) {
        unordered_map<int, int> count;      // {group: count}
        unordered_map<int, long long> dist; // {group: distance sum}
        
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            auto [childCnt, childDist] = dfs(nxt, curr, graph, group);

            for (auto [k, v]:childCnt) {
                if (count.contains(k)) {
                    res += count[k]*childDist[k] + v*dist[k];
                }
                // update count and dist from current subtree
                count[k] += v;
                dist[k] += childDist[k];
            }
        }

        if (count.contains(group[curr])) {
            res += dist[group[curr]];
        }

        for (auto [k, v]:dist) {
            dist[k] += count[k];
        }

        // include curr        
        count[group[curr]]++;
        dist[group[curr]]++;

        return {count, dist};
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs(0, -1, graph, group);

        return res;
    }
};


// Fast, count how many times each edge is used
class Solution {
public:
    long long res = 0;
    vector<long long> groupCnt = vector<long long>(21, 0);   // cannot write `vector<long long> groupCnt(21, 0);` here
    long long dfs(int curr, int parent, int groupNum, vector<vector<int>>& graph, vector<int>& group) {
        
        long long cnt = (group[curr] == groupNum?1:0);
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            long long subCnt = dfs(nxt, curr, groupNum, graph, group);
            res += subCnt*(groupCnt[groupNum] - subCnt);
            cnt += subCnt;
        }

        return cnt;
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        // groupCnt.resize(21, 0);
        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for (int i=0; i<n; i++) {
            groupCnt[group[i]]++;
        }

        for (int groupNum=1; groupNum <=20; groupNum++) {
            dfs(0, -1, groupNum, graph, group);
        }
        
        return res;
    }
};