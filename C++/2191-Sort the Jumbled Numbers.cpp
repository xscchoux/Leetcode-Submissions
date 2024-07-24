// custom comparator using lambda function + stable sort (very slow, just practice)
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto compare = [mapping](int a, int b) {
            int newA = 0, indA = 0;
            if (a == 0) newA = mapping[a];
            while (a > 0) {
                newA += mapping[a%10]*pow(10, indA);
                a = a/10;
                indA++;
            }

            int newB = 0, indB = 0;
            if (b == 0) newB = mapping[b];
            while (b > 0) {
                newB += mapping[b%10]*pow(10, indB);
                b = b/10;
                indB++;
            }
            return newA < newB;
        };
        stable_sort(nums.begin(), nums.end(), compare);

        return nums;
    }
};




// sort a pair
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> pairs;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                pairs.push_back({mapping[0], i});
                continue;
            }
            int place = 1, temp = nums[i], mapped = 0;
            while (temp > 0) {
                mapped = place*mapping[temp%10] + mapped;
                temp = temp/10;
                place*=10;
            }
            pairs.push_back({mapped, i});
        }

        sort(pairs.begin(), pairs.end());
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            res.push_back(nums[pairs[i].second]);
        }

        return res;
    }
};