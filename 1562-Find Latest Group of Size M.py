class Solution(object):
    def findLatestStep(self, arr, m):
        """
        :type arr: List[int]
        :type m: int
        :rtype: int
        """
        n = len(arr)
        length = [0]*(n+2)
        count = [0]*(n+2)
        
        res = -1
        for i in range(len(arr)):
            x = arr[i]
            if length[x]:
                continue
            left = length[x-1]
            right = length[x+1]
            total = left + right + 1
            length[x-left] = length[x+right] = total
            count[left] -= 1
            count[right] -= 1
            count[total] += 1
            if count[m]:
                res = i+1
        return res