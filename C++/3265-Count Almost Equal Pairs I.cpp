class Solution {
public:
    int countPairs(vector<int>& nums) {
        int N = nums.size();
        sort(nums.rbegin(), nums.rend());
        unordered_map<int, int> cnt;
        int res = 0;

        for (int num:nums) {
            res += cnt[num];    
            unordered_set<int> s;
            string numString = to_string(num); 
            int size = numString.size();
            s.insert(num);

            for (int i=0; i<size; i++) {
                for (int j=i+1; j<size; j++) {
                    swap(numString[i], numString[j]);
                    s.insert(stoi(numString));
                    swap(numString[j], numString[i]);
                }
            }
            for (int stored:s) {
                cnt[stored]++;
            }
        }
        return res;
    }
};