class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int mx = *max_element(begin(groups), end(groups));
        vector<int> pos(mx+1, -1);

        for (int i=0; i<elements.size(); i++) {
            int curr = elements[i];
            if (curr <= mx && pos[curr] == -1) {
                while (curr <= mx) {
                    if (pos[curr] == -1) pos[curr] = i;
                    curr += elements[i];
                }
            }
        }

        vector<int> res;
        for (int i=0; i<groups.size(); i++) {
            if (pos[groups[i]] == -1) {
                res.push_back(-1);
            } else {
                res.push_back(pos[groups[i]]);
            }
        }

        return res;
    }
};