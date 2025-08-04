// O(30*N)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, tmp;

        for (int x:arr) {
            unordered_set<int> nxt;
            for (int y:tmp) {       // O(30)
                nxt.insert(x|y);
            }
            nxt.insert(x);
            res.insert(begin(nxt), end(nxt));
            tmp = nxt;
        }

        return res.size();
    }
};


// Use only one set, clever and efficient, but O(n^2) in worst case
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;

        for (int i=0; i<arr.size(); i++) {
            res.insert(arr[i]);
            int j= i-1;
            int without = 0, with = arr[i];
            while (j >= 0) {
                with |= arr[j];
                without |= arr[j];
                if (with == without) break;
                res.insert(with);
                j--;
            }
        }

        return res.size();
    }
};