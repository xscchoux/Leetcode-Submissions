class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for (int i=1; i<=n; i++) arr.push_back(i);
        int curr = 0;

        while (arr.size() > 1) {
            int N = arr.size();
            curr = (curr + k-1)%N;
            arr.erase(arr.begin() + curr);
            curr = curr%(N-1);
        }
        return arr[curr];
    }
};