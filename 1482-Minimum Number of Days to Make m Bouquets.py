class Solution(object):
    def minDays(self, bloomDay, m, k):
        """
        :type bloomDay: List[int]
        :type m: int
        :type k: int
        :rtype: int
        """
        if m*k > len(bloomDay):
            return -1
        
        def IsEnough(targetDay):
            count = 0
            tot = 0
            for day in bloomDay:
                count = count + 1 if day <= targetDay else 0
                if count == k:
                    count = 0
                    tot += 1
                    if tot == m:
                        return True
        
        left, right = 1, max(bloomDay)
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if IsEnough(mid):
                right = mid
            else:
                left = mid
        
        if IsEnough(left):
            return left
        elif IsEnough(right):
            return right
        else:
            return -1