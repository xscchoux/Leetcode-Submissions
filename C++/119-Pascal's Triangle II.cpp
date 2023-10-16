class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curr = vector(1, 1);
        for (int row = 1; row <= rowIndex; row++){
            vector<int> nxt = vector(row+1, 0);
            for (int i=0; i<curr.size(); i++){
                nxt[i] += curr[i];
                nxt[i+1] += curr[i];
            }
            curr = move(nxt); // Use std::move() to transfer ownership of memory, printing nxt[0] will give error
        }
        return curr;
    }
};