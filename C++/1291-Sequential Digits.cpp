class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int> nums;
        for (int length = to_string(low).size(); length <= to_string(high).size(); length++){
            for (int start=0; start < 10-length; start++) {
                int num = stoi(str.substr(start, length));
                if (num >= low && num <= high) nums.push_back(num);
            }
        }
        return nums;
    }
};