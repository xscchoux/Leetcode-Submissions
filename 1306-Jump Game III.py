class Solution(object):
    def canReach(self, arr, start):
        """
        :type arr: List[int]
        :type start: int
        :rtype: bool
        """
# O(n), DFS traversal of the array
        visited = set()
        self.res = False
        N = len(arr)-1
        def dfs(start):
            if start in visited or start <0 or start > N:
                return
            visited.add(start)
            if arr[start] == 0:
                self.res = True
                return
            for _next in (start+arr[start], start-arr[start]):
                dfs(_next)
        dfs(start)
        return self.res