class Solution(object):
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        visited = [0]*len(rooms)
        visited[0] = 1
        
        def dfs(key):
            if visited[key] == 1:
                return
            visited[key] = 1
            for nxt in rooms[key]:
                dfs(nxt)
        
        
        for i in range(len(rooms)):
            if visited[i]:
                for key in rooms[i]:
                    dfs(key)
        
        return False if sum(visited) != len(visited) else True