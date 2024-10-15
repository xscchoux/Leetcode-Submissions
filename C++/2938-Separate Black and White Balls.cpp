// first AC
class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        vector<int> arr;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '1') {
                arr.push_back(i);
            }
        }

        int right = s.size()-1;
        for (int ind=arr.size()-1; ind>=0; ind--) {
            res += right-arr[ind];
            right--;
        }

        return res;
    }
};

// Ideal solution
class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        int black = 0;
        for (char c:s) {
            if (c == '1') black++;
            else res += black;
        }

        return res;
    }
};