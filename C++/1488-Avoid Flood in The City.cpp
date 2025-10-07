// First AC
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> prePos;
        int N = rains.size();
        set<int> zeroPos;
        vector<int> arr;

        for (int i=0; i<rains.size(); i++) {
            if (rains[i] == 0) {
                zeroPos.insert(i);
                arr.push_back(0);
            } else if (!prePos.contains(rains[i])) {
                arr.push_back(-1);
                prePos[rains[i]] = i;
            } else { // cnt.contains(rain)
                if (zeroPos.size() > 0) {
                    int preIdx = prePos[rains[i]];
                    auto zeroIt = zeroPos.lower_bound(preIdx);
                    if (zeroIt == zeroPos.end()) return {};
                    arr[*zeroIt] = rains[i];
                    zeroPos.erase(zeroIt);
                    arr.push_back(-1);
                    prePos[rains[i]] = i;
                } else {
                    return {};
                }
            }
        }

        for (int i=0; i<arr.size(); i++) {
            if (arr[i] == 0) {
                arr[i] = 1;
            }
        }

        return arr;
    }
};

// Better
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> prePos;
        int N = rains.size();
        set<int> zeroPos;
        vector<int> arr;

        for (int i=0; i<rains.size(); i++) {
            if (rains[i] == 0) {
                zeroPos.insert(i);
                arr.push_back(0);
            } else {
                if (prePos.contains(rains[i])) {
                    auto zeroIt = zeroPos.lower_bound(prePos[rains[i]]);
                    if (zeroIt == zeroPos.end()) return {};
                    arr[*zeroIt] = rains[i];
                    zeroPos.erase(zeroIt);
                }
                prePos[rains[i]] = i;
                arr.push_back(-1);
            }
        }

        for (int i=0; i<arr.size(); i++) {
            if (arr[i] == 0) {
                arr[i] = 1;
            }
        }

        return arr;
    }
};