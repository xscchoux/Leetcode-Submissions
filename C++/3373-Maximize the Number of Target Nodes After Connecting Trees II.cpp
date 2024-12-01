class Solution {
public:
    int evenEdgeNodes(int curr, int parent, vector<vector<int>>& graph, int step) {
        int tot = (step%2?0:1);

        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            tot += evenEdgeNodes(nxt, curr, graph, step+1);
        }

        return tot;
    }
    void fillCnt1(int curr, int parent, vector<vector<int>>& graph, vector<int>& cnt, int step, int count, int sz) {
        cnt[curr] = (step%2==0?count:(sz-count));
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            fillCnt1(nxt, curr, graph, cnt, step+1, count, sz);
        }
       
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int sz1 = edges1.size() + 1, sz2 = edges2.size() + 1;
        vector<vector<int>> graph1(sz1), graph2(sz2);

        for (auto &e:edges1) {
            int u = e[0], v = e[1];
            graph1[u].push_back(v);
            graph1[v].push_back(u);
        }

        for (auto &e:edges2) {
            int u = e[0], v = e[1];
            graph2[u].push_back(v);
            graph2[v].push_back(u);
        }

        vector<int> cnt1(sz1); // count of nodes within even edges for each node
        cnt1[0] = evenEdgeNodes(0, -1, graph1, 0);
        fillCnt1(0, -1, graph1, cnt1, 0, cnt1[0], sz1);

        int cnt2 = evenEdgeNodes(0, -1, graph2, 0); // count of nodes within even edges for node0

        int maxOddEdgeNodes = max(cnt2, sz2-cnt2);
        
        for (int i=0; i<sz1; i++) {
            cnt1[i] += maxOddEdgeNodes;
        }

        return cnt1;
    }
};