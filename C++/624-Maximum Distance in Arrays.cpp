class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int first = -1e4, second = -1e4;
        for (vector<int> &a:arrays){
            if (a[a.size()-1] > first){
                second = first;
                first = a[a.size()-1];
            } else if (a[a.size()-1] > second){
                second = a[a.size()-1];
            }
        }
        
        int res = 0;
        for (auto &a:arrays){
            if (a[a.size()-1] == first){
                res = max(res, second - a[0]);
            } else {
                res = max(res, first - a[0]);
            }
        }
        return res;
    }
};



// straightforward multiset solution
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        multiset<pair<int, int>> minset, maxset;
        int res = 0;
        for (int i=0; i<arrays.size(); i++) {
            int mn = arrays[i][0], mx = arrays[i].back();
            minset.insert({mn, i});
            maxset.insert({mx, i});
            if (minset.size() > 2) {
                minset.erase(prev(minset.end()));  // cannot use reverse iterator here
            }
            if (maxset.size() > 2) {
                maxset.erase(maxset.begin());
            }
        }

        for (auto it1 = minset.begin(); it1 != minset.end(); it1++) {
            for (auto it2 = maxset.begin(); it2 != maxset.end(); it2++) {
                if ((*it1).second != (*it2).second) {
                    res = max(res, (*it2).first - (*it1).first);
                }
            }
        }

        return res;
    }
};


// fastest
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalMax = INT_MIN/2, globalMin = INT_MAX/2;
        int res = 0;
        for (auto &array:arrays) {
            int mn = array[0], mx = array.back();
            res = max({res, globalMax-mn, mx-globalMin});
            globalMax = max(mx, globalMax);
            globalMin = min(mn, globalMin);
        }

        return res;
    }
};