class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int N = fruits.size(), used = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<baskets.size(); j++) {
                if (baskets[j]>=fruits[i]) {
                    used++;
                    baskets.erase(find(begin(baskets), end(baskets), baskets[j]));
                    break;
                }
            }
        }

        return N-used;
    }
};