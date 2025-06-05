struct UnionFind {
    vector<int> parent, rank;
    explicit UnionFind(int n) : parent(vector<int>(n)), rank(vector<int>(n, 1)) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    bool unite(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);
        if(p1 == p2) return false; // Same parent
        if(rank[p1] >= rank[p2]) {
            // Append p2 under p1
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        for (int i=0; i<s1.size(); i++) {
            uf.unite(s1[i] - 'a', s2[i] - 'a');
        }

        vector<int> smallest(26, 26);
        for (int i=0; i<26; i++) {
            int root = uf.find(i);
            if (smallest[root] == 26) {
                smallest[i] = smallest[root] = i;
            } else {
                smallest[i] = smallest[root];
            }
        }

        string res;
        for (char c:baseStr) {
            res += smallest[c-'a'] + 'a';
        }

        return res;
    }
};