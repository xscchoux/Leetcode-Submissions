class Solution {
public:
    int maxTransactions(vector<int>& transactions) {
        priority_queue<int, vector<int>, greater<>> pq;
        int N = transactions.size(), res = 0;
        long long tot = 0;
        
        for (int i=0; i<N; i++) {
            tot += transactions[i];
            if (transactions[i] < 0) pq.push(transactions[i]);
            res++;
            if (tot < 0) {
                tot -= pq.top();
                pq.pop();
                res--;
            }
        }

        return res;
    }
};