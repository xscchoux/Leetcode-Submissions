class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size(), n = values[0].size();
        long res = 0;
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
        for (int i=0; i<m; i++){
            int val = values[i][values[i].size()-1];
            values[i].pop_back();
            pq.push({val, i});
        }
        
        for (int i=1; i<=m*n; i++){
            auto [val, idx] = pq.top();
            pq.pop();
            res += val*i;
            if (!values[idx].empty()){
                int v = values[idx][values[idx].size()-1];
                values[idx].pop_back();
                pq.push({v, idx});
            }
        }
        return res;        
    }
};