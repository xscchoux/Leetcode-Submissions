/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int maxDepth = 0;
    void dfs(vector<NestedInteger>& nestedList, unordered_map<int, int>& cnt, int depth) {
        maxDepth = max(depth, maxDepth);
        
        for (auto sl:nestedList) {
            if (sl.isInteger()) {
                cnt[depth] += sl.getInteger();
            } else {
                dfs(sl.getList(), cnt, depth+1);
            }
        }
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {

        unordered_map<int, int> cnt;  // depth: sum of numbers
        
        dfs(nestedList, cnt, 1);

        int res = 0;

        for (auto &[k, v]:cnt) {
            res += (maxDepth-k+1)*v;
        }

        return res;
    }
};