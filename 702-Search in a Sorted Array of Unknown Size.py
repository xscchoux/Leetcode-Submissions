# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader(object):
#    def get(self, index):
#        """
#        :type index: int
#        :rtype int
#        """

class Solution(object):
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
# brute force
        # tmp = reader.get(0)
        # k = 0
        # while tmp != 2147483647:
        #     if tmp > target:
        #         return -1
        #     if target == tmp:
        #         return k
        #     k+=1
        #     tmp = reader.get(k)
        # return -1
    
# binary search
        left, right = 0, 1
        while reader.get(right) < target:
            left = right
            right *= 2
        
        while left + 1 < right:
            mid = left + (right-left)//2
            num = reader.get(mid)
            if num < target:
                left = mid
            elif num > target:
                right = mid
            else:
                return mid
        
        if reader.get(left) == target:
            return left
        elif reader.get(right) == target:
            return right
        else:
            return -1