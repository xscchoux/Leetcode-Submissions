class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int N = weights.size();
        vector<int> pairVal;
        for (int i=0; i<N-1; i++) {
            pairVal.push_back(weights[i]+weights[i+1]);
        }

        sort(begin(pairVal), end(pairVal));

        long long res = 0;
        for (int i=0; i<k-1; i++) {
            res += pairVal[N-2-i] - pairVal[i];
        }

        return res;
    }
};