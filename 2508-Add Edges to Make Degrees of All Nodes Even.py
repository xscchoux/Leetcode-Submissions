class Solution:
    def isPossible(self, n: int, edges: List[List[int]]) -> bool:
# only need to consider the case when the number of odd degree node is 0, 2, 4
        connect = [set() for _ in range(n)]
        
        for u, v in edges:
            connect[u-1].add(v-1)
            connect[v-1].add(u-1)
        needone = [i for i in range(n) if len(connect[i])%2 == 1]
        
        def notNeighbor(a, b):
            return a not in connect[b]
        
        if len(needone) == 2:
            p1, p2 = needone
            if notNeighbor(p1, p2):
                return True
            for i in range(n):
                if i not in (p1, p2) and notNeighbor(p1, i) and notNeighbor(p2, i):
                    return True
            return False
        
        if len(needone) == 4:
            p1, p2, p3, p4 = needone
            if (notNeighbor(p1, p2) and notNeighbor(p3, p4)) or (notNeighbor(p1, p3) and notNeighbor(p2, p4)) or (notNeighbor(p1, p4) and notNeighbor(p2, p3)):
                return True

        return len(needone) == 0