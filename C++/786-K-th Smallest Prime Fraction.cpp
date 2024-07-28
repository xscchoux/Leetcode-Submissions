// naive solution，O(N^2 log(N^2))
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int N = arr.size();
        vector<tuple<float, int, int>> a;
        for (int i=1; i<N; i++) {
            for (int j=0; j<i; j++) {
                a.push_back({arr[j]/float(arr[i]), arr[j], arr[i]});
            }
        }
        sort(a.begin(), a.end());

        return {get<1>(a[k-1]), get<2>(a[k-1])};
    }
};


// Use priority queue, O((N+k)*log(N))
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int N = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq;

        for (int i=0; i<N-1; i++) {
            pq.push({-1.0*arr[i]/arr.back(), {i, N-1}});
        }

        while (k-- > 1) {
            auto [start, end] = pq.top().second;
            pq.pop();
            end -= 1;
            if (end > start) {
                pq.push({-1.0*arr[start]/arr[end], {start, end}});
            }
        }

        auto &[s, e] = pq.top().second;

        return {arr[s], arr[e]};
    }
};