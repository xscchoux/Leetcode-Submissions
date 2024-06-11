class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int N = arr.size();
        unordered_map<int, int> prefixCount;  // Maps to store counts and totals of XOR values encountered
        unordered_map<int, int> sumOfIndex;   // Maps to store totals of index values with the same prefix XOR
        prefixCount[0] = 1;
        sumOfIndex[0] = -1;

        vector<int> prefixArr;
        int curr = 0;
        for (int num:arr) {
            curr = curr^num;
            prefixArr.push_back(curr);
        }

        int res = 0;
        for (int i=0; i<prefixArr.size(); i++) {
            res += prefixCount[prefixArr[i]]*(i-1) - sumOfIndex[prefixArr[i]];
            prefixCount[prefixArr[i]]++;
            sumOfIndex[prefixArr[i]] += i;
        }

        return res;
    }
};