class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        // count gives elements going downhill
        int N = weight.size(), count = 0, res = 0;

        for (int i=0; i<N; i++) {
            if (i > 0 && weight[i] < weight[i-1]) {
                if (count == 0) {
                    count = 2;
                } else {
                    count++;
                }
            } else {
                res += count/2;
                count = 0;
            }
        }
        res += count/2;

        return res;
    }
};