class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int N = s.size(), tot = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == '1') tot++;
        }

        vector<pair<int, int>> arr;
        for (int i=0; i<N; i++) {
            if (s[i] == '0') {
                int curr = i;
                arr.push_back({curr, curr});
                while (s[curr] == '0') {
                    curr++;
                }
                arr.back().second = curr-1;
                i = curr;
            }
        }

        if (arr.size() <= 1) {
            return tot;
        } else {
            int toAdd = 0;
            for (int i=0; i<arr.size()-1; i++) {
                toAdd = max(toAdd, arr[i].second-arr[i].first+1 + arr[i+1].second-arr[i+1].first+1) ;
            }
            return tot + toAdd;
        }
    }
};