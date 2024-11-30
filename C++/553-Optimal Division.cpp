class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string first = to_string(nums[0]);
        if (nums.size() == 1) return first;
        if (nums.size() == 2) return first + "/" + to_string(nums[1]);

        first += "/(";
        for (int i=1; i<nums.size(); i++) {
            first += to_string(nums[i]) + "/";
        }
        first.pop_back();
        first += ")";
        return first;
    }
};