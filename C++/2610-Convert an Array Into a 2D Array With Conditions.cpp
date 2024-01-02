class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> hmap;
        for (int x:nums){
            hmap[x]++;;
        }
        
        vector<vector<int>> arr;
        
        while (hmap.size() > 0){
            vector<int> tmp;
            auto it = hmap.begin();
            while (it != hmap.end()){
                tmp.push_back(it->first);
                if (--it->second == 0){
                    it = hmap.erase(it);
                } else {
                    it++;
                }
            }
            arr.push_back(tmp);
        }
        return arr;
    }
};