class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        sortedArr = sorted(nums1)
        N = len(nums1)
        res = 0
        modify = 0
        kMod = 10**9+7
        
        tot = 0
        
        for i in range(N):
            tot = (tot + abs(nums1[i]-nums2[i]))%kMod
        res = tot
        
        for i in range(len(nums1)):
            left, right = 0, N-1
            while left + 1 < right:
                mid = left + (right-left)//2
                if sortedArr[mid] > nums2[i]:
                    right = mid
                else:
                    left= mid
                    
            tmp = (tot - abs(nums1[i]-nums2[i]) + min(abs(sortedArr[left]-nums2[i]), abs(sortedArr[right]-nums2[i])))
            res = min(res, tmp)
        
        return res%kMod


# Revisit

class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        sortedArr = sorted(nums1)
        N = len(nums1)
        kMod = 10**9+7
        original = 0
        
        for i in range(N):
            original = (original + abs(nums1[i]-nums2[i]))%kMod

        res = original
        
        for i in range(N):
            idx = bisect_left(sortedArr, nums2[i])
            diff = abs(nums2[i]-nums1[i])
            for j in range(idx-1, idx+1):
                if 0<=j<len(nums1):
                    res = min(res, original-diff+abs(nums2[i]-sortedArr[j]))
        
        return res%kMod