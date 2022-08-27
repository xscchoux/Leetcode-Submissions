class Solution(object):
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
# O(row*row*col*col)
        row = len(matrix)
        col = len(matrix[0])
        res = float('-inf')
        
        for r1 in range(row):
            colList = [0]*col
            for r2 in range(r1, row):
                tot, slist = 0, []
                for c in range(col):
                    colList[c] += matrix[r2][c]
                    tot += colList[c]
                    if tot <= k:
                        res = max(res, tot)
                    index = bisect.bisect_left(slist, tot - k)
                    if index != len(slist):
                        res = max(res, tot - slist[index])
                    if res == k:
                        return k
                    bisect.insort(slist, tot)
        return res


# using SortedList

from sortedcontainers import SortedList
class Solution(object):
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        row, col = len(matrix), len(matrix[0])
        res = float('-inf')
        
        for r in range(row):
            dp = [0]*col
            for r1 in range(r, row):
                tot, slist = 0, SortedList()
                for c in range(col):
                    dp[c] += matrix[r1][c]
                    tot += dp[c]
                    if tot <= k:
                        res = max(res, tot)
                    index = slist.bisect_left(tot-k)
                    if index != len(slist):
                        res = max(res, tot-slist[index])
                    if res == k:
                        return res
                    slist.add(tot)
        return res