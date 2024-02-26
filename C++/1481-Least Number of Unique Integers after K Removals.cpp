class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> hmap;
        for (int num:arr) hmap[num]++;
        
        sort(arr.begin(), arr.end(), [&](int a, int b){ return hmap[a] < hmap[b]||(hmap[a]==hmap[b] && a<b);});
        unordered_set<int> s;
        
        for (int i=k; i<arr.size(); i++) {
            s.insert(arr[i]);
        }
        
        return (int)s.size();
    }
};