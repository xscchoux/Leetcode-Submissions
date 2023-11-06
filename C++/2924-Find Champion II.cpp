class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        int res = -1;
        for (vector<int>& edge:edges){
            indegree[edge[1]] += 1;
        }
        bool found = false;
        for (int i=0; i<n; i++){
            if (indegree[i] == 0){
                if (!found){
                    res = i;
                    found = true;
                }
                else return -1;
            }
        }
        return res;
    }
};