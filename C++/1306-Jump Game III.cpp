class Solution {
public:
    bool dfs(int curr, vector<int>& arr, vector<bool>& visited) {
        if (arr[curr] == 0) return true;
        visited[curr] = true;

        if (curr + arr[curr] < arr.size() && !visited[curr+arr[curr]] && dfs(curr+arr[curr], arr, visited)) {
            return true;
        }
        if (curr - arr[curr] >= 0 && !visited[curr-arr[curr]] && dfs(curr-arr[curr], arr, visited)) {
            return true;
        }

        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int N = arr.size();

        if (arr[start] == 0) return true;

        vector<bool> visited(N);

        return dfs(start, arr, visited);
    }
};