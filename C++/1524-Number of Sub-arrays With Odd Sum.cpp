class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int even = 1, odd = 0, curr = 0, res = 0, kMod = 1e9+7;
        for (int i=0; i<arr.size(); i++) {
            curr += arr[i];
            if (curr%2) {
                res += even;
                odd++;
            } else {
                res += odd;
                even++;
            }
            res%=kMod;
        }

        return res;
    }
};