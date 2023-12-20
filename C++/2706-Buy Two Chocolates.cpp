class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int large1 = 100, large2 = 100;
        for (int p:prices){
            if (p < large1){
                large2 = large1;
                large1 = p;
            } else if (p < large2){
                large2 = p;
            }
        }
        
        return (large1 + large2 <= money)?(money-large1-large2):money;
    }
};