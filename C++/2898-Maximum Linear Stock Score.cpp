class Solution {
public:
    long long maxScore(vector<int>& prices) {
        unordered_map<long, long> hmap;
        for (int i = 0; i < prices.size(); i++){
            hmap[prices[i] - i - 1] += prices[i];
        }
        long res = 0;
        for (auto pair:hmap){
            res = max(res, pair.second);
        }
        return res;
    }
};