class Solution {
public:
    int kill;
    void dfs(int curr, int parent, unordered_map<int, vector<int>>& graph, int needKill, vector<int>& res) {
        
        if (curr == kill) {
            needKill = 1;
        }
        if (needKill) {
            res.push_back(curr);
        }
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            dfs(nxt, curr, graph, needKill, res);
        }


    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        this->kill = kill;
        int N = pid.size();
        unordered_map<int, vector<int>> graph;
        int root = -1;
        for (int i=0; i<N; i++) {
            graph[ppid[i]].push_back(pid[i]);
            if (ppid[i] == 0) {
                root = pid[i];
            }
        }

        vector<int> res;
        dfs(root, 0, graph, 0, res);


        return res;
    }
};