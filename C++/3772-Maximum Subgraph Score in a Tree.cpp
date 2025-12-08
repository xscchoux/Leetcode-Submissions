// First AC
class Solution {
public:
    // subTreeMax[curr]: the maximum possible score from subtree rooted at node curr
    vector<int> subTreeMax;
    // allTree[curr]: the maximum possible score among all connected subgraphs that contain node curr
    vector<int> allTree;
    int dfs(int curr, int parent, const vector<vector<int>>& graph, const vector<int>& good) {
        int currVal = (good[curr] == 1)?1:-1;
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            int val  = dfs(nxt, curr, graph, good);
            if (val > 0) {
                currVal += val;
            }
        }
        return subTreeMax[curr] = currVal;
    }

    void dfs2(int curr, int parent, const vector<vector<int>>& graph, const vector<int>& good) {
        if (parent == -1) {
            allTree[curr] = subTreeMax[curr]; 
        } else {
            int parentVal = allTree[parent];
            int subTreeVal = subTreeMax[curr];
            if (subTreeVal >= 0) {  // subTree is in allTree[parent]
                allTree[curr] = max(parentVal, subTreeVal);
            } else {  // subTree in not in allTree[parent]
                allTree[curr] = max(parentVal + (good[curr] == 1?1:-1), subTreeVal);
            }
        }

        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            dfs2(nxt, curr, graph, good);
        }
    }  

    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        subTreeMax.resize(n, 0);
        allTree.resize(n, 0);
        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1, graph, good);
        // re-rooting
        dfs2(0, -1, graph, good);

        vector<int> res;
        for (int i=0; i<n; i++) {
            res.push_back(allTree[i]);
        }

        return res;
    }
};



// Better 
class Solution {
public:
    vector<int> subTreeMax;
    
    // subTreeMax[curr]: the maximum possible score from subtree rooted at node curr
    int dfs(int curr, int parent, const vector<vector<int>>& graph, const vector<int>& good) {
        int currVal = (good[curr] == 1)?1:-1;
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            int val  = dfs(nxt, curr, graph, good);
            if (val > 0) {
                currVal += val;
            }
        }
        return subTreeMax[curr] = currVal;
    }

    // other: scores from trees other than current subtree
    // subTreeMax[curr]: the maximum possible score among all connected subgraphs that contain node curr
    void dfs2(int curr, int parent, int other, const vector<vector<int>>& graph, const vector<int>& good) {
        subTreeMax[curr] += max(0, other);
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            dfs2(nxt, curr, subTreeMax[curr] - max(0, subTreeMax[nxt]), graph, good);
        }
    }  

    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        subTreeMax.resize(n, 0);

        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1, graph, good);
        // re-rooting
        dfs2(0, -1, 0, graph, good);

        return subTreeMax;
    }
};