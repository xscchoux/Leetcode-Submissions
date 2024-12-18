class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        stack<int> stk;
        prices.push_back(0);
        for (int i=0; i<=N; i++) {
            while (!stk.empty() && prices[i] <= prices[stk.top()]) {
                prices[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }

        prices.pop_back();
        return prices;
    }
};