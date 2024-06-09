class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> arr(n, 1);
        int kMod = 1e9+7;

        for (int i=1; i<=k; i++) {
            for (int j=1; j<n; j++) {
                arr[j] = (arr[j] + arr[j-1])%kMod;
            }
        }

        return arr[n-1];

    }
};