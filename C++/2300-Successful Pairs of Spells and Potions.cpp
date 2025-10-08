class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions), end(potions));
        int N = potions.size();
        vector<int> arr;

        for (int spell:spells) {
            int idx = lower_bound(begin(potions), end(potions), (success+spell-1)/spell) - begin(potions);
            arr.push_back(N-idx);
        }

        return arr;
    }
};