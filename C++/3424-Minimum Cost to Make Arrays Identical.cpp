class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int N = arr.size();
        long long diff1 = 0, diff2 = 0;
        for (int i=0; i<N; i++) {
            diff1 += abs(arr[i]-brr[i]);
        }

        sort(begin(arr), end(arr));
        sort(begin(brr), end(brr));

        for (int i=0; i<N; i++) {
            diff2 += abs(arr[i]-brr[i]);
        }

        return min(diff1, diff2+k);
    }
};