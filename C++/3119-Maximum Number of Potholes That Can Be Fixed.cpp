class Solution {
private:
    int cnt = 0, res = 0;
    vector<int> holes;
public:
    int maxPotholes(string road, int budget) {

        int N = road.size();
        for (int i=0; i<=N; i++) {
            if (road[i] == 'x') {
                cnt++;
            } else if (cnt > 0) {
                holes.push_back(cnt);
                cnt = 0;
            }
        }
        
        if (cnt > 0) holes.push_back(cnt);
        
        sort(holes.begin(), holes.end(), greater<int>());
        
        for (int c:holes) {
            if (c+1 < budget) {
                res += c;
                budget -= (c+1);
            } else {
                res += (budget-1);
                break;
            }
        }
        
        return res;
    }
};

// second visit
class Solution {
public:
    int maxPotholes(string road, int budget) {
        vector<int> potholeArr;
        int cnt = 0;
        for (int i=0; i<road.size(); i++) {
            int j = i;
            while (j < road.size() && road[j] == 'x') j++;
            j -= 1;
            if (j-i+1 > 0) potholeArr.push_back(j-i+1);
            i = j+1;
        }

        sort(potholeArr.begin(), potholeArr.end(), greater<>());
        int idx = 0, res = 0;
        while (budget > 1 && idx < potholeArr.size()) {
            int x = min(potholeArr[idx]+1, budget);
            budget -= x;
            res += x-1;
            idx++;
        }

        return res;
    }
};