// O(Nk)
class Solution {
public:
    void addNum(list<int>& l, int val) {
        l.push_back(val);

        for (auto it = --l.end(); it != l.begin();) {
            auto prevIt = prev(it);
            if (*prevIt <= *it) break;
            swap(*it, *prevIt);   // note the way we swap values in a list, iter_swap also works
            // iter_swap(it, prevIt);
            it--; 
        }

    }
    vector<int> minSubarraySort(vector<int>& nums, int k) {
        int N = nums.size();
        list<int> sortedNums;  // use list here because its inserting operation is O(1)
        vector<int> res;
        
        for (int i=0; i<N; i++) {
            addNum(sortedNums, nums[i]);  // insert and also sort the list
            if (i >= k-1) {
                int len = 0;
                auto it = sortedNums.begin();
                for (int j=i-k+1; it != sortedNums.end(); it++, j++) {
                    if (*it != nums[j]) break;
                    len++;
                }
                if (it != sortedNums.end()) {
                    auto reverseIt = --sortedNums.end();
                    for (int j = i; j>=i-k+1; reverseIt--, j--) {
                        if (*reverseIt != nums[j]) break;
                        len++;
                    }
                }
                res.push_back(k-len);
                sortedNums.erase(find(begin(sortedNums), end(sortedNums), nums[i-k+1]));
            }
        }

        return res;
    }
};