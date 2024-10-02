class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> arr2;
        for (int i=0; i<arr.size(); i++) {
            arr2.push_back({arr[i], i});
        }
        sort(begin(arr2), end(arr2));

        int rank = 0;
        for (int i=0; i<arr.size(); i++) {
            if (i > 0 && arr2[i].first == arr2[i-1].first) {
                arr[arr2[i].second] = rank;
            } else {
                arr[arr2[i].second] = ++rank;
            }
        }

        return arr;
    }
};