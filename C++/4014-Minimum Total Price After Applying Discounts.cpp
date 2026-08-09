class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(begin(discounts), end(discounts), greater<>());
        sort(begin(prices), end(prices), greater<>());        

        double res = 0;
        int discountIdx = 0;
        for (int i=0; i<prices.size(); i++) {
            if (discountIdx < discounts.size()) {
                res += (double)prices[i]*(100-discounts[discountIdx])/100;
                discountIdx++;
            } else {
                res += prices[i];
            }
        }

        return res;
    }
};