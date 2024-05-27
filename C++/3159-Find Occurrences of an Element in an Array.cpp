class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indArr;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == x) indArr.push_back(i);
        }

        vector<int> res;
        for (int q:queries) {
            if (q > indArr.size()) res.push_back(-1);
            else res.push_back(indArr[q-1]);
        }

        return res;
    }
};