class Solution {
public:
    int k;
    int getCount(int curr, int parent, vector<vector<int>>& graph, int step) {
        if (step > k) return 0;
        int tot = 1;

        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            tot += getCount(nxt, curr, graph, step+1);
        }

        return tot;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        this->k = k;
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

        vector<int> cnt1(sz1); // count of nodes within k edges for each node
        for (int i=0; i<sz1; i++) {
            cnt1[i] = getCount(i, -1, graph1, 0);
        }

        vector<int> cnt2(sz2); // count of nodes within k-1 edges for each node
        for (int i=0; i<sz2; i++) {
            cnt2[i] = getCount(i, -1, graph2, 1);
        }
        int mxCnt2 = *max_element(begin(cnt2), end(cnt2));

        for (int i=0; i<sz1; i++) {
            cnt1[i] += mxCnt2;
        }

        return cnt1;
    }
};