class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mx = *max_element(begin(lights), end(lights));
        
        int res = 0;
        for (int i=0; i<arrivalTime.size(); i++) {
            int t = arrivalTime[i]%period;
            if (t < mx) continue;
            res = max(res, period-t);
        }

        return res;
    }
};