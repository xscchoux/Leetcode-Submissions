class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> arr;

        for (int num:nums) {
            long long curr = num;
            while (!arr.empty() && curr == arr.back()) {
                arr.pop_back();
                curr = curr*2;
            }
            arr.push_back(curr);
        }

        return arr;
    }
};