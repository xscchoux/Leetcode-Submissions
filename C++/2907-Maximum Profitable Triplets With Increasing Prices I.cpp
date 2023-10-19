class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int res = -1;
        
        for (int j = 1; j < prices.size()-1; j++){
            int mid = prices[j];
            int left = 0, right = 0;
            for (int i = 0; i < j; i++){
                if (mid > prices[i]) left = max(left, profits[i]);
            }
            for (int k = prices.size()-1; k > j; k--){
                if (mid < prices[k]) right = max(right, profits[k]);
            }
            
            if (right && left){
                res = max(res, left + profits[j] + right);
            }
        }
        return res;
    }
};