class Solution(object):
    def findLengthOfShortestSubarray(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
# https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/discuss/830699/Python-Two-Pointers-Approach-with-Explanation
# 1. l is the last index of prefix such that arr[l+1] < arr[l]
# 2. r is the first index of suffix such that arr[r-1] > arr[r]
# 3. Try to "merge 2 sorted arrays"

        l, r = 0, len(arr)-1
        
        while l < r:
            if arr[l] > arr[l+1]:
                break
            l += 1
            
        if l == r:
            return 0
        
        while r > l:
            if arr[r] < arr[r-1]:
                break
            r -= 1
            
        toRemove = min(len(arr)-l-1, r)
        
        for idx in range(l+1):
            if arr[idx] <= arr[r]:
                toRemove = min(toRemove, r-idx-1)
            elif r < len(arr) - 1:
                r += 1
            else:
                break
        
        return toRemove