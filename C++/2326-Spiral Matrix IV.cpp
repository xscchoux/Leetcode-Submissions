/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int r=0, c=0;
        int dirIdx = 0;

        while (head != nullptr) {
            matrix[r][c] = head->val;
            head = head->next;
            int nr = r + directions[dirIdx][0], nc = c + directions[dirIdx][1];
            if (min(nr, nc) < 0 || nc>=n || nr >= m || matrix[nr][nc] != -1) {
                dirIdx = (dirIdx+1)%4;
            }
            r += directions[dirIdx][0];
            c += directions[dirIdx][1];
        }
            
        return matrix;
    }
};