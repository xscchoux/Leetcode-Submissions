class Solution {
public:
    int budget;
    tuple<vector<int>, vector<int>, int> dfs(int curr, vector<int>& present, vector<int>& future, vector<vector<int>>& graph) {
        int cost = present[curr], halfCost = cost/2;
        
        // dp0:max profit without buying its parent, dp1:max profit with buying its parent
        vector<int> dp0(budget+1, 0), dp1(budget+1, 0);

        // subDp0:max profit from subtrees without buying its parent, subDp1: max profit from subtrees with buying its parent
        vector<int> subDp0(budget+1, 0), subDp1(budget+1, 0);

        int treeCost = 0;
        treeCost += cost;

        // Each time we take one subtree into consideration:
        // dp0[budget] = max(dp0[budget], subDp0[budget - current subtree budget] + (dp0 from current subtree)[current subtree budget])
        // current subtree budget: 0 ~ budget

        for (int nxt:graph[curr]) {
            auto [nxtSubDp0, nxtSubDp1, nxtSubCost] = dfs(nxt, present, future, graph);
            treeCost += nxtSubCost;
            for (int i=budget; i>=0; i--) {
                for (int currSubTreeBudget = 0; currSubTreeBudget <= min(nxtSubCost, i); currSubTreeBudget++) {
                    subDp0[i] = max(subDp0[i], subDp0[i-currSubTreeBudget] + nxtSubDp0[currSubTreeBudget]);
                    subDp1[i] = max(subDp1[i], subDp1[i-currSubTreeBudget] + nxtSubDp1[currSubTreeBudget]);
                }
            }
        }

        // fill dp0 and dp1
        for (int i = 0; i <= budget; i++) {
            dp0[i] = dp1[i] = subDp0[i];
            if (i >= cost) {
                dp0[i] = max(dp0[i], subDp1[i-cost] + future[curr] - cost);
            }
            if (i >= halfCost) {
                dp1[i] = max(dp1[i], subDp1[i-halfCost] + future[curr] - halfCost);
            }
        }

        return {dp0, dp1, treeCost};
    }
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        this->budget = budget;
        vector<vector<int>> graph(n);
        for (auto &h:hierarchy) {
            graph[h[0]-1].push_back(h[1]-1);
        }

        auto resTuple = dfs(0, present, future, graph);

        return get<0>(resTuple)[budget];
    }
};