class Solution(object):
    def outerTrees(self, trees):
        """
        :type trees: List[List[int]]
        :rtype: List[List[int]]
        """
# Jarvis algorithm, O(m*n), n:number of trees, m: number of hull points
        n = len(trees)    
    
        # check if vector ac is clockwise to vector ab
        def isClockwise(a, b, c):
            return (c[0]-a[0])*(b[1]-a[1]) - (c[1]-a[1])*(b[0]-a[0])
        
        if len(trees) < 4:
            return trees
        
        leftMostIdx = 0
        
        for i, (x, y) in enumerate(trees):
            if x < trees[leftMostIdx][0]:
                leftMostIdx = i
                
        currIdx = leftMostIdx
        res = set()
        
        
        while True:
            cand = (currIdx+1)%n
            for i in range(n):
                if isClockwise(trees[currIdx], trees[cand], trees[i]) > 0:
                    cand = i
            
            for i in range(n):
                if isClockwise(trees[currIdx], trees[cand], trees[i]) == 0:
                    res.add((trees[i][0], trees[i][1]) )
            
            if cand == leftMostIdx:
                break
                
            currIdx = cand
                
        return list(res)
    
# Monotone chain, O(nlogn)
        
        n = len(trees)
        if n < 4:
            return trees
        
        def isClockwise(a, b, c):
            return (c[0]-a[0])*(b[1]-a[1]) - (c[1]-a[1])*(b[0]-a[0])
        
        trees.sort(key = lambda x:(x[0], x[1]))
        
        upper = []
        for i in range(len(trees)):
            while len(upper)>=2 and isClockwise(upper[-2], upper[-1], trees[i]) < 0:
                upper.pop()
            upper.append(trees[i])  
        
        lower = []
        for i in range(len(trees)-1, -1, -1):
            while len(lower) >= 2 and isClockwise(lower[-2], lower[-1], trees[i]) < 0:
                lower.pop()
            lower.append(trees[i])
        
        return list(map(list, set(map(tuple, lower[:-1] + upper[:-1]))))