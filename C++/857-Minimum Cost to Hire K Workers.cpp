class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int N = quality.size();
        vector<pair<double, int>> arr;
        for (int i=0; i<N; i++) {
            arr.push_back({(double)wage[i]/quality[i], quality[i]});
        }

        sort(arr.begin(), arr.end());
        
        int curr = 0;
        priority_queue<int, vector<int>> pq;

        for (int i=0; i<k; i++) {
            pq.push(arr[i].second);
            curr += arr[i].second;
        }
        
        double res = curr*arr[k-1].first;

        for (int i=k; i<N; i++) {
            curr -= pq.top();
            pq.pop();
            pq.push(arr[i].second);
            curr += arr[i].second;
            res = min(res, curr*arr[i].first);
        }

        return res;
    }
};