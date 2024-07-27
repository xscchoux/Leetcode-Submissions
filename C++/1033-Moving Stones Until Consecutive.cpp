class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> arr = {a, b, c};
        sort(arr.begin(), arr.end());

        int mn = 0, mx = 0;
        int diff1 = arr[1]-arr[0]-1, diff2 = arr[2]-arr[1]-1;

        if (diff1 == 1 || diff2 == 1) mn = 1;  // for the case: a = 3, b = 5, c = 1
        else mn += (diff1 > 0) + (diff2 > 0);

        mx += diff1 + diff2;

        return {mn, mx};
    }
};