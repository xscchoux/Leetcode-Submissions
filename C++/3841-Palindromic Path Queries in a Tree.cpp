class SGTree {
    vector<int> seg;
public:
    SGTree(int n) {
        seg.resize(4 * n + 1, 0);
    }

    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l) return 0;

        // complete overlap
        // [l low high r]
        if (low >= l && high <= r) return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left^right;
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] ^= val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = seg[2 * ind + 1]^seg[2 * ind + 2];
    }
};


class Solution {
public:
    int n;
    void dfs(int curr, int parent, int& time, vector<int>& tin, vector<int>& tout, vector<vector<int>>& graph, vector<vector<int>>& binaryLifting, vector<int>& depth) {
        tin[curr] = time; // the time we enter current node
        binaryLifting[curr][0] = parent;
        time++;

        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            depth[nxt] = depth[curr] + 1;
            dfs(nxt, curr, time, tin, tout, graph, binaryLifting, depth);
        }

        tout[curr] = time-1; // the time we leave the last node in the subtree of curr node
    }

    // build binary lifting table
    void build(vector<vector<int>>& binaryLifting, int maxPower) {
        for (int power=1; power<=maxPower; power++) {
            for (int curr=0; curr<n; curr++) {
                if (binaryLifting[curr][power-1] == -1) continue;
                binaryLifting[curr][power] = binaryLifting[binaryLifting[curr][power-1]][power-1];
            }
        }
    }

    int getLCA(int u, int v, vector<vector<int>>& binaryLifting, vector<int>& depth, int maxPower) {
        if (depth[u] < depth[v]) swap(u, v);
        // move u to the same level as v
        for (int jump = maxPower; jump>=0; jump--) {  
            int diffD = depth[u] - depth[v];
            if (diffD < (1<<jump)) {
                continue;
            }
            u = binaryLifting[u][jump];
        }

        if (u == v) return u;

        // find common parent node
        for (int jump = maxPower; jump>=0; jump--) {
            if (binaryLifting[u][jump] != binaryLifting[v][jump]) {
                u = binaryLifting[u][jump];
                v = binaryLifting[v][jump];
            }
        } 

        return binaryLifting[u][0];
    }


    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int maxPower = log2(n) + 1;
        vector<vector<int>> binaryLifting(n, vector<int>(maxPower+1, -1));
        vector<int> depth(n, 0), tin(n, 0), tout(n, 0);
        int time = 0;
        dfs(0, -1, time, tin, tout, graph, binaryLifting, depth);

        build(binaryLifting, maxPower);

        SGTree sgt(n+1);

        for (int i=0; i<s.size(); i++) {
            sgt.update(0, 0, n, tin[i], 1<<(s[i]-'a'));
            sgt.update(0, 0, n, tout[i]+1, 1<<(s[i]-'a'));
        }

        vector<bool> res;

        for (auto &q:queries) {
            stringstream ss(q);
            string operation;
            ss >> operation;
            if (operation == "update") {
                int idx;
                char newChar;
                ss >> idx >> newChar;

                int delta = (1<<(s[idx]-'a'))^(1<<(newChar-'a'));
                sgt.update(0, 0, n, tin[idx], delta);
                sgt.update(0, 0, n, tout[idx]+1, delta);
                s[idx] = newChar;
            } else {
                int u, v;
                ss >> u >> v;
                int lca = getLCA(u, v, binaryLifting, depth, maxPower);
                int pathU = sgt.query(0, 0, n, 0, tin[u]), pathV = sgt.query(0, 0, n, 0, tin[v]);
                int pathXOR = pathU^pathV^(1<<(s[lca]-'a'));
                if (pathXOR == 0 || (pathXOR&(pathXOR-1)) == 0) {
                    res.push_back(true);
                } else {
                    res.push_back(false);
                }

            }
        }

        return res;
    }
};