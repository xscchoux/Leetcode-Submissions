class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> arr;
        for (auto &t:timePoints) {
            int hour = stoi(t.substr(0, 2));
            int minute = stoi(t.substr(3, 2));
            arr.push_back(hour*60+minute);
        }
        sort(arr.begin(), arr.end());
        int res = INT_MAX;
        for (int i=1; i<arr.size(); i++) {
            res = min(res, arr[i]-arr[i-1]);
            if (res == 0) return 0;
        }
        res = min(res, 1440-(arr[arr.size()-1]-arr[0]) );

        return res;
    }
};