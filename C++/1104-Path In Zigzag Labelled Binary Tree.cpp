class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> arr;
        while (label != 1) {
            arr.push_back(label);
            int level = log2(label) + 1;
            int num = (label%static_cast<int>(pow(2, level-1)))/2;
            label = pow(2,level-2) + (pow(2, level-2)-num-1);
        }
        arr.push_back(1);
        reverse(arr.begin(), arr.end());

        return arr;
    }
};