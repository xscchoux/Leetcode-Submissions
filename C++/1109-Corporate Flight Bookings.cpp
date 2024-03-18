class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2, 0);
        for (auto arr:bookings) {
            int s = arr[0], e = arr[1], seat = arr[2];
            diff[s] += seat;
            diff[e+1] -= seat;
        }
        
        for (int i=1; i<=n; i++) {
            diff[i] += diff[i-1];
        }
        
        return {diff.begin()+1, diff.end()-1};
    }
};