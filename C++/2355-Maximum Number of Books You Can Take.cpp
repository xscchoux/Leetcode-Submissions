class Solution {
public:
    long long calculateSum(int start, int end, vector<int>& books) {
        int length = min(end-start+1, books[end]);
        return (long long)(books[end] + (books[end]-length+1))*length/2;
    }
    long long maximumBooks(vector<int>& books) {
        int N = books.size();
        vector<long long> dp(N+1, 0);
        stack<int> stk;

        for (int i=0; i<N; i++) {
            while (!stk.empty() && books[i] - (i-stk.top()) <= books[stk.top()]) {
                stk.pop();
            }
            if (stk.empty()) {
                dp[i] = calculateSum(0, i, books);
            } else {
                dp[i] = dp[stk.top()] + calculateSum(stk.top()+1, i, books);
            }
            stk.push(i);
        }

        return *max_element(begin(dp), end(dp));
    }
};