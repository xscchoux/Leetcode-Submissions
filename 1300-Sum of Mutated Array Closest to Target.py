class Solution(object):
    def findBestValue(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
# binary search (O(N*logM)), N:length of arr, M:max(arr)

        def cal(res):
            return sum([res if val > res else val for val in arr])
        
        left, right = 0, max(arr)
        
        while left + 1 < right:
            mid = left + ((right-left)>>1)
            if cal(mid) == target:
                return mid
            elif cal(mid) < target:
                left = mid
            else:
                right = mid
        if abs(cal(right) - target) >= abs(cal(left)-target):
            return left
        else:
            return right