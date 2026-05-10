class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        array<int, 3> targetArray = {target[0], target[1], target[2]};

        set<array<int, 3>> s;
        for (auto &p : points) {
            s.insert({p[0], p[1], p[2]});
        }

        int step = 0, sz = s.size();
        while (true) {
            
            if (s.contains(targetArray)) return step;
            
            set<array<int, 3>> newS;
            
            for (auto it = s.begin(); it != s.end(); it++) {
                auto t1 = *it;
                for (auto it2 = next(it); it2 != s.end(); it2++) {
                    auto t2 = *it2;
                    newS.insert({(t1[0] + t2[0])/2, (t1[1]+t2[1])/2, (t1[2]+t2[2])/2});
                }
            }

            for (auto it = newS.begin(); it != newS.end(); it++) {
                s.insert(*it);
            }

            if (sz == s.size()) return -1;
            sz = s.size();

            step++;
        }

        return true;
    }
};