// time complexity: O(6! * N^4), I may be wrong
class Solution {
public:
    set<vector<int>> s;
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int N = nums2.size();
        queue<vector<int>> q;

        vector<int> target(N), start(N);
        for (int i=0; i<nums2.size(); i++) {
            target[i] = nums2[i];
            start[i] = nums1[i];
        }

        int step = 0;
        q.push(start);
        s.insert(start);

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto curr = q.front();
                if (curr == nums2) {
                    return step;
                }
                q.pop();
                for (int left=0; left<N; left++) {
                    for (int right=left; right<N; right++) {

                        vector<int> toInsert;
                        toInsert.insert(toInsert.end(), begin(curr)+left, begin(curr)+right+1);
                        vector<int> tmp = curr;
                        tmp.erase(begin(tmp)+left, begin(tmp)+right+1);

                        for (int i=0; i<=tmp.size(); i++) {
                            vector<int> newArr = tmp;
                            newArr.insert(begin(newArr)+i, begin(toInsert), end(toInsert));
                            if (!s.contains(newArr)) {
                                s.insert(newArr);
                                q.push(newArr);
                            }
                        }
                    }
                }
            }
            step++;
        }

        return 0;
    }
};