class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> hmap;
        for (vector<string> item:access_times){
            string key = item[0];
            string time = item[1];
            hmap[key].push_back(stoi(time.substr(0, 2))*60 + stoi(time.substr(2)));
        }

        vector<string> res;
        
        for (auto &[k, v]:hmap){
            if (v.size() < 3) continue;
            sort(v.begin(), v.end());
            for (int i=2; i<v.size(); i++){
                if (v[i] - v[i-2] < 60){
                    res.push_back(k);
                    break;
                }
            }
        }
        
        return res;
    }
};