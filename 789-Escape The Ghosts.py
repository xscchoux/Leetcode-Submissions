class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        def dist(A, B):
            return abs(A[0]-B[0]) + abs(A[1]-B[1])
        
        return all(dist([0, 0], target) < dist(G, target) for G in ghosts)