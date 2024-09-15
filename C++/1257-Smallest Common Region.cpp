class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        
        for (auto &r:regions) {
            for (int i=1; i<r.size(); i++) {
                parent[r[i]] = r[0];
            }
        }

        unordered_set<string> p1;
        p1.insert(region1);
        while (parent.contains(region1)) {
            region1 = parent[region1];
            p1.insert(region1);
        }

        while (true) {  // It is guaranteed the smallest region exists.
            if (p1.contains(region2)) {
                return region2;
            }
            region2 = parent[region2];
        }

        // return "";  // we don't need this
    }
};