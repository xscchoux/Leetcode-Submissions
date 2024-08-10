// Pixelation (upscale three times)
class Solution {
private:
    void dfs(vector<vector<int>>& arr, int i, int j, int sideLen) {
        if (i<0 || i==sideLen || j<0 || j==sideLen) return;
        if (arr[i][j] == 1) return;
        arr[i][j] = 1;
        dfs(arr, i+1, j, sideLen);
        dfs(arr, i, j+1, sideLen);
        dfs(arr, i-1, j, sideLen);
        dfs(arr, i, j-1, sideLen);        
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        vector<vector<int>> arr(3*N, vector<int>(3*N, 0));
        int res = 0;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (grid[i][j] == '/') {
                    arr[3*i][3*j+2] = 1;
                    arr[3*i+1][3*j+1] = 1;
                    arr[3*i+2][3*j] = 1;
                } else if (grid[i][j] == '\\') {
                    arr[3*i][3*j] = 1;
                    arr[3*i+1][3*j+1] = 1;
                    arr[3*i+2][3*j+2] = 1;
                } else {
                    continue;
                }
            }
        }

        for (int i=0; i<3*N; i++) {
            for (int j=0; j<3*N; j++) {
                if (!arr[i][j]) {
                    dfs(arr, i, j, 3*N);
                    res++;
                }
            }
        }
        return res;
    }
};




// Divide each cell into four triangles
// ---------
//  \  0  /
//  3 \ / 1
//    / \
//  /  2  \
// ---------

class DSU {
    private:
        vector<int> parent;
    public:
        DSU (int N): parent(N) {
            for (int i=0; i<N; i++) {
                parent[i] = i;
            }
        }
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        void merge(int a, int b) {
            int pa = find(a), pb = find(b);
            parent[pa] = pb;
        }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        DSU dsu(4*N*N);

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (grid[i][j] == '/') {
                    dsu.merge(4*(i*N+j)+0, 4*(i*N+j)+3);
                    dsu.merge(4*(i*N+j)+1, 4*(i*N+j)+2);
                    if (j<N-1) {
                        dsu.merge(4*(i*N+j)+1, 4*(i*N+j+1)+3);
                    }
                } else if (grid[i][j] == '\\') {
                    dsu.merge(4*(i*N+j)+0, 4*(i*N+j)+1);
                    dsu.merge(4*(i*N+j)+2, 4*(i*N+j)+3);
                    if (j<N-1) {
                        dsu.merge(4*(i*N+j)+1, 4*(i*N+j+1)+3);
                    }                
                } else {
                    dsu.merge(4*(i*N+j)+0, 4*(i*N+j)+1);
                    dsu.merge(4*(i*N+j)+1, 4*(i*N+j)+2);
                    dsu.merge(4*(i*N+j)+2, 4*(i*N+j)+3);
                    if (j<N-1) {
                        dsu.merge(4*(i*N+j)+1, 4*(i*N+j+1)+3);
                    }         
                }

                if (i != N-1) {
                    dsu.merge(4*(i*N+j)+2, 4*((i+1)*N+j)+0);
                }
            }
        }

        int res = 0;
        for (int i=0; i<4*N*N; i++) {
            if (dsu.find(i) == i) res++;
        }
        return res;
    }
};