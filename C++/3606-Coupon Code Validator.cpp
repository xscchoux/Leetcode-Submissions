class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int N = code.size();
        unordered_map<string, int> hmap = {{"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};

        vector<pair<string, string>> arr;

        for (int i=0; i<N; i++) {
            if (!isActive[i] || code[i].empty() || !hmap.contains(businessLine[i])) continue;
            bool flag = true;
            for (char c:code[i]) {
                if (c == '_' || isalnum(c)) continue;
                flag = false;
            }
            if (flag) {
                arr.push_back({businessLine[i], code[i]});
            }
        }
        sort(arr.begin(), arr.end());

        vector<string> res;
        for (int i=0; i<arr.size(); i++) {
            res.push_back(arr[i].second);
        }

        return res;

    }
};