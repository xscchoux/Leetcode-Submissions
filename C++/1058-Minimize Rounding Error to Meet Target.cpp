// My solution
// O(n*target), n = prices.length
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        vector<float> arr;
        for (string p : prices) arr.push_back(stof(p));

        unordered_map<int, float> preHmap;  // val, cost
        preHmap[0] = 0;
        for (auto p : arr) {
            unordered_map<int, float> newMap;

            for (auto [k, v] : preHmap) {
                int upper = ceil(p), lower = floor(p);
                if (k+upper<=target) {
                    newMap[k+upper] = newMap.contains(k+upper)?min(newMap[k+upper], v+upper-p):v+upper-p;
                }
                if (k+lower<=target) {
                    newMap[k+lower] = newMap.contains(k+lower)?min(newMap[k+lower], v+p-lower):v+p-lower;
                }
            }
            preHmap = move(newMap);
        }

        if (!preHmap.contains(target) || preHmap[target] < 0) return "-1";
        string res = to_string(round(preHmap[target]*1000)/ 1000);
        auto pos = res.find('.');
        return res.substr(0, pos+4);
    }
};



// O(nlogn), very clever solution
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        priority_queue<float, vector<float>, greater<>> diff;
        float tot = 0, res = 0;
        for (string p:prices) {
            float curr = stof(p);
            tot += floor(curr);
            res += curr-floor(curr);
            if (ceil(curr) != floor(curr)) diff.push((ceil(curr)-curr) - (curr-floor(curr)));  // does need to put the difference in pq when the element is like 2.000, 3.000, ...
        }
        if (tot > target || tot + diff.size() < target) return "-1";
        int ceil_operations = target - tot;
        while (ceil_operations-- > 0) {
            res += diff.top();
            diff.pop();
        }

        string resString = to_string(round(res*1000)/1000);
        int pos = resString.find('.');
        return resString.substr(0, pos+4);
    }
};