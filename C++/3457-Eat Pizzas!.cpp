class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int days = pizzas.size()/4;
        int odd = (days+1)/2, even = days/2;
        sort(begin(pizzas), end(pizzas));

        long long res = 0;
        int idx = pizzas.size()-1;
        for (int i=1; i<=odd; i++) {
            res += pizzas[idx--];
        }

        for (int i=1; i<=even; i++) {
            idx--;
            res += pizzas[idx--];
        }        

        return res;
    }
};