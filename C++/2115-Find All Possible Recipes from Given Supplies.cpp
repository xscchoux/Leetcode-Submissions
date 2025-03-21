// toplogical sort
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        int N = recipes.size();
        queue<string> q;

        for (string &s:supplies) {
            indegree[s] = 0;
            q.push(s);
        }
        
        for (int i=0; i<N; i++) {
            for (string &s:ingredients[i]) {
                graph[s].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        unordered_set<string> recipeSet(begin(recipes), end(recipes));

        vector<string> res;

        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                string curr = q.front();
                q.pop();
                if (recipeSet.contains(curr)) res.push_back(curr);
                for (string &nxt:graph[curr]) {
                    indegree[nxt]--;
                    if (indegree[nxt] == 0) {
                        q.push(nxt);
                    }
                }
            }
        }

        return res;
    }
};



// better toplogical sort solution
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        int N = recipes.size();
        vector<string> res;
        queue<string> q;

        unordered_set<string> supplySet(begin(supplies), end(supplies));
        
        for (int i=0; i<N; i++) {
            int indegreeCnt = ingredients[i].size();
            for (string &s:ingredients[i]) {
                if (supplySet.contains(s)) {
                    indegreeCnt--;
                } else {
                    graph[s].push_back(recipes[i]);
                    indegree[recipes[i]]++;

                }
            }
            if (indegreeCnt == 0) {
                res.push_back(recipes[i]);
                q.push(recipes[i]);
            }
        }


        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                string curr = q.front();
                q.pop();
                for (string &nxt:graph[curr]) {
                    indegree[nxt]--;
                    if (indegree[nxt] == 0) {
                        res.push_back(nxt);
                        q.push(nxt);
                    }
                }
            }
        }

        return res;
    }
};