class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned.sort()
        banned.append(n+1)

        def isOK(maxNum):
            prev = 1
            tot = 0
            for num in banned:
                if num == prev:
                    continue
                if maxNum < num:
                    tot += (maxNum+prev+1)*(maxNum-prev)//2
                    break
                else:
                    tot += (num+prev)*(num-prev-1)//2
                prev = num
            return tot <= maxSum
        
        left, right = 1, n   # maximum number
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                left = mid
            else:
                right = mid
        
        if isOK(right):
            res = right
            for i in range(len(banned)):
                if i > 0 and banned[i] == banned[i-1]:
                    continue
                if banned[i] <= right:
                    res -= 1
                else:
                    break
            return res
        else:
            res = left
            for i in range(len(banned)):
                if i > 0 and banned[i] == banned[i-1]:
                    continue
                if banned[i] <= left:
                    res -= 1
                else:
                    break
            return res