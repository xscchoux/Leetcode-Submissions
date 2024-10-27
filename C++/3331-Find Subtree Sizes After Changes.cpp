class Solution {
public:
    void dfs(int curr, vector<vector<int>>& graph, vector<vector<int>>& preIdx, vector<int>& parent, string& s) {
        if (preIdx[s[curr]-'a'].size() > 0) {
            parent[curr] = preIdx[s[curr]-'a'].back();
        }
        preIdx[s[curr]-'a'].push_back(curr);
        for (int nxt:graph[curr]) {
            dfs(nxt, graph, preIdx, parent, s);
        }
        preIdx[s[curr]-'a'].pop_back();
    }
    int cal(int curr, vector<vector<int>>& graph2, vector<int>& res) {
        int tot = 1;
        for (int nxt:graph2[curr]) {
            tot += cal(nxt, graph2, res);
        }
        res[curr] = tot;
        return tot;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int N = s.size();
        vector<vector<int>> graph(N);
        for (int i=0; i<N; i++) {
            if (parent[i] == -1) continue;
            graph[parent[i]].push_back(i);
        }

        vector<vector<int>> preIdx(26); // index of closest ancestor with same value

        dfs(0, graph, preIdx, parent, s); // update parent

        vector<vector<int>> graph2(N); 

        for (int i=0; i<N; i++) {   // reconstruct the graph based on updated parent
            if (parent[i] == -1) continue;
            graph2[parent[i]].push_back(i);
        }

        vector<int> res(N);
        cal(0, graph2, res);    // calculate subtree size
        return res;
    }
};