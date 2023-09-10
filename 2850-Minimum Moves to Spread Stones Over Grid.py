class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:   
# BFS
        flatGrid = [grid[i][j] for i in range(3) for j in range(3)]
        initialState = tuple(flatGrid)
        targetState = tuple([1] * 9)
        visited = set()
        visited.add(initialState)
        queue = deque([(0, initialState)])  #queue where each element is a tuple (cost, state).
        moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        while queue:
            cost, state = queue.popleft()
            if state == targetState:
                return cost
            emptyArr = []
            
            for i in range(len(state)):
                if state[i] == 0:
                    emptyArr.append(i)
                    
            for idx in emptyArr:
                currR = idx//3
                currC = idx%3
                for dr, dc in moves:
                    newR, newC = currR+dr, currC+dc
                    if 0<=newR<3 and 0<=newC<3:
                        newIndex = newR*3+newC
                        if state[newIndex] != 0:
                            newState = list(state)
                            newState[newIndex] -= 1
                            newState[idx] += 1
                            stateTuple = tuple(newState)
                            if stateTuple not in visited:
                                queue.append((cost+1, stateTuple))
                                visited.add(stateTuple)

# Permutation, O(8*8!)
        zeros = []
        excess = []
        for r in range(3):
            for c in range(3):
                if grid[r][c] == 0:
                    zeros.append((r, c))
                elif grid[r][c] > 1:
                    for _ in range(grid[r][c]-1):
                        excess.append((r, c))

        N = len(zeros)
        res = float('inf')

        for zeroArr in permutations(zeros):
            tot = 0
            for i in range(len(zeroArr)):
                (zeroR, zeroC) = zeroArr[i]
                tot += abs(excess[i][0]-zeroR) + abs(excess[i][1]-zeroC)
            res = min(res, tot)
        
        return res