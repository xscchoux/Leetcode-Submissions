class Solution(object):
    def shortestDistanceColor(self, colors, queries):
        """
        :type colors: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        
# O(N)
        n = len(colors)
        leftmost, rightmost = [n-1]*n, [0]*n
        distance = [ [-1]*n for _ in range(3)]
        
        
        for i in range(len(colors)):
            color = colors[i]-1
            for j in range(rightmost[color], i+1):
                distance[color][j] = i-j
            rightmost[color] = i
            
        for i in range(len(colors)-1, -1, -1):
            color = colors[i]-1
            for j in range(leftmost[color], i-1, -1):
                if distance[color][j] == -1 or distance[color][j] > j - i:
                    distance[color][j] = j-i
                leftmost[color] = i
        
        res = []
        for query in queries:
            res.append(distance[query[1]-1][query[0]])
        return res
        
    
# O(Q*logN + N), Q:length of queries
        hmap = {1:[], 2:[], 3:[]}
        
        for ind, color in enumerate(colors):
            hmap[color].append(ind)
        
        res = []
        
        def bsearch(ind, color):
            arr = hmap[color]
            l, r = 0, len(arr)-1
            while l+1 < r:
                mid = l + (r-l)//2
                if arr[mid] == ind:
                    return 0
                elif arr[mid] < ind:
                    l = mid
                else:
                    r = mid
            return min(abs(ind-arr[l]), abs(arr[r]-ind))
                    
        for query in queries:
            if not hmap[query[1]]:
                res.append(-1)
            else:
                res.append(bsearch(query[0], query[1]))
        
        return res