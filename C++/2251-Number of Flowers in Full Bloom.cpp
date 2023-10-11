class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> gain;
        vector<int> loss;
        
        for (int i=0; i<flowers.size(); i++){
            gain.push_back(flowers[i][0]);
            loss.push_back(flowers[i][1]+1);
        }
        
        sort(gain.begin(), gain.end());
        sort(loss.begin(), loss.end());
        
        vector<int> res;
        for (int p:people){
            // Returns an iterator pointing to the first element in the range [first,last) which compares greater than val
            int add = upper_bound(gain.begin(), gain.end(), p) - gain.begin();
            int minus = upper_bound(loss.begin(), loss.end(), p) - loss.begin();
            res.push_back(add-minus);
        }
        
        return res;
    }
};