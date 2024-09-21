class Solution {
public:
    static bool cmp(int a, int b) {
        string A = to_string(a), B = to_string(b);
        return A<B;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> arr;
        for (int i=1; i<=n; i++) {
            arr.push_back(i);
        }

        sort(arr.begin(), arr.end(), cmp);

        return arr;
    }
};