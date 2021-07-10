import heapq
class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        N = len(matrix)
        heap = []
        
        if k < N*N//2:
            for r in range(min(k,N)):
                heappush(heap, (matrix[r][0], r, 0) )

            while k > 0:
                curr, r, c = heappop(heap)
                if c < N-1:
                    heappush(heap, (matrix[r][c+1], r, c+1))
                k -= 1

            return curr
        else:
            backwardKth = N*N - k + 1
            for r in range(N-1, max(N-1 - backwardKth, -1), -1):
                heappush(heap, (-matrix[r][N-1], r, N-1) )
            
            while backwardKth > 0:
                curr, r, c = heappop(heap)
                if c > 0:
                    heappush(heap, (-matrix[r][c-1], r, c-1))
                backwardKth -= 1
            return -curr

# Binary Search (difficult to come up with)
        n = len(matrix)
        
        def countLessEqual(target):
            r, c = n-1, 0
            res = 0
            while r>=0 and c < n:
                if matrix[r][c] <= target:
                    res += r+1
                    c += 1
                else:
                    r -= 1
            return res
        
        left, right = matrix[0][0], matrix[-1][-1]
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if countLessEqual(mid) < k:
                left = mid
            else:
                right = mid
        if countLessEqual(left) >= k:
            return left
        else:
            return right