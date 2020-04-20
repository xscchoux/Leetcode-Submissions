from collections import defaultdict
class Solution(object):
    def minTransfers(self, transactions):
        """
        :type transactions: List[List[int]]
        :rtype: int
        """

# time complexity: O (m + (N-1)!), m: length of transactions, N: number of people

        balances = defaultdict(int)
        for x, y, z in transactions:
            balances[x] -= z
            balances[y] += z
        
        ids = []
        for key in balances:
            if balances[key] != 0:
                ids.append(balances[key])
        N = len(ids)
        self.count = float('inf')
        
        
        def dfs(start, count):
            while start < N and ids[start] == 0:
                start += 1
            if start >= N:
                if count < self.count:
                    self.count = count
                return
            
            for i in range(start+1, N):
                if ids[start]*ids[i] < 0:
                    ids[i] += ids[start]
                    dfs(start+1, count+1)
                    ids[i] -= ids[start]
                    
                    if ids[i] + ids[start] == 0:  # pruning
                        break
                        
        dfs(0,0)
        return self.count