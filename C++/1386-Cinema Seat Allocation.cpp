class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        unordered_map<int, vector<int>> hmap;
        for (auto seat:reservedSeats) {
            int key = seat[0], val = seat[1];
            hmap[key].push_back(val);
        }

        int res = 0;
        for (auto &[k, v]:hmap) {
            if (v.size() == 1) {
                int idx = v[0];
                if (idx == 1 || idx == 10) res += 2;
                else res++;
            } else {
                int prev = -1;
                v.push_back(11);
                for (int idx:v) {
                    if (prev <= 1 && idx >= 10) res += 2;
                    else if ((prev <= 3 && idx >= 8) || (prev <= 1 && idx >= 6) || (prev <= 5 && idx >= 10)) res++; // two seats reserved
                    prev = idx;
                }
            }
        }

        res += (n - hmap.size())*2;

        return res;
    }
};