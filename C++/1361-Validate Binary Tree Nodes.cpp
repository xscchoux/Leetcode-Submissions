class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree = vector(n, 0);
        
        for (int i=0; i<n; i++){
            if (leftChild[i] != -1) indegree[leftChild[i]]++;
            if (rightChild[i] != -1) indegree[rightChild[i]]++;
        }
        
        int index = -1;
        for (int i=0; i<n; i++){
            if (indegree[i] == 0){
                index = i;
                break;
            }
        }
        
        if (index == -1) return false;
        unordered_set<int> visited;
        visited.insert(index);
        queue<int> queue;
        queue.push(index);
        
        while (!queue.empty()){
            int length = queue.size();
            for (int i=0; i<length; i++){
                int curr = queue.front();
                queue.pop();
                int left = leftChild[curr], right = rightChild[curr];
                if (left != -1){
                    if (visited.find(left) != visited.end()){
                        return false;
                    }
                    visited.insert(left);
                    queue.push(left);
                }
                if (right != -1){
                    if (visited.find(right) != visited.end()){
                        return false;
                    }
                    visited.insert(right);
                    queue.push(right);
                }
                
            }
        }
        return visited.size() == n;      
    }
};