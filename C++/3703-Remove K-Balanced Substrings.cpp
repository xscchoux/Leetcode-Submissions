class Solution {
public:
    string removeSubstring(string s, int k) {
        int curr = 0;
        // open:positive, close:negative
        vector<int> arr;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                if (arr.empty() || arr.back() < 0) {
                    arr.push_back(1);
                } else {
                    arr.back() += 1;
                }
            } else {
                if (arr.empty() || arr.back() > 0) {
                    arr.push_back(-1);
                } else {
                    arr.back() -= 1;
                }

                // remove
                if (arr.back() == -k && arr.size() >= 2 && arr[arr.size()-2] >= k) {
                    arr.pop_back();
                    arr.back() -= k;
                    if (arr.back() == 0) {
                        arr.pop_back();
                    }
                }
            }
        }

        string ans = "";
        for (int i=0; i<arr.size(); i++) {
            if (arr[i] > 0) {
                for (int k=0; k<arr[i]; k++) ans += '(';
            } else if (arr[i] < 0) {
                for (int k=arr[i]; k<0; k++) {
                    ans += ')';
                }
            } 
        }

        return ans;
    }
};