class Solution {
public:
    bool isOK(int number, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        if (not number) return true;
        deque<int> queue;
        int taskIdx = 0, N = workers.size();
        for (int i = N-number; i < N; i++){
            while (taskIdx < number && workers[i] + strength >= tasks[taskIdx]){
                queue.push_back(tasks[taskIdx]);
                taskIdx++;
            }
            if (queue.empty()) return false;
            if (workers[i] >= queue.front()){
                queue.pop_front();
            } else if (pills){
                pills--;
                queue.pop_back();
            } else{
                return false;
            }
        }
        return true;
    }
    
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int left = 0, right = min(tasks.size(), workers.size());
        while (left + 1 < right){
            int mid = left + (right-left)/2;
            if (isOK(mid, tasks, workers, pills, strength)) left = mid;
            else right = mid;
        }
        if (isOK(right, tasks, workers, pills, strength)) return right;
        else return left;
    }
};