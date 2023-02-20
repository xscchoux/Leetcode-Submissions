class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        # https://www.youtube.com/watch?v=WL_M1yk1pKE
        """
        [[4,0,2,0],  1st character == 3rd character
         [0,3,0,1],  2nd character == 4th character
         [2,0,2,0],  1st character == 3rd character
         [0,1,0,1]]  2nd character == 4th character
        """
        N = len(lcp)
        parent = {i:i for i in range(N)}
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            parent[pa] = pb
            
        for i in range(N):
            if lcp[i][i] != N-i:
                return ""
            for j in range(i+1, N):
                if lcp[i][j] != lcp[j][i]:
                    return ""
                if j + lcp[i][j] > N:
                    return ""
                if lcp[i][j]:
                    union(i, j)
        
        word = []
        lookup = dict()
        d = 0
        for i in range(N):
            p = find(i)
            if p not in lookup:
                lookup[p] = d
                d += 1
            word.append(chr(ord('a') + lookup[p]))
        
        if d >= 27:
            return ""
        
        lcp2 = [[0]*N for _ in range(N)]
        for i in range(N-1, -1, -1):
            for j in range(N-1, -1, -1):
                if word[i] == word[j]:
                    lcp2[i][j] = 1
                    if i < N-1 and j < N-1:
                        lcp2[i][j] = lcp2[i+1][j+1] + 1
        
        if lcp2 != lcp:
            return ""
        return "".join(word)