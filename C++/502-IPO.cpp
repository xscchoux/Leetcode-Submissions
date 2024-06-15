class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> arr;
        int N = profits.size();
        for (int i=0; i<N; i++) {
            arr.push_back({capital[i], profits[i]});
        }

        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>> pq;

        for (int i=0; i<N; i++) {
            while (w < arr[i].first && k > 0 && !pq.empty()) {
                k--;
                w += pq.top();
                pq.pop();
            }
            if (w >= arr[i].first) pq.push(arr[i].second);
            else break;
        }

        while (k>0 && !pq.empty()) {
            w += pq.top();
            pq.pop();
            k--;
        }

        return w;
    }
};