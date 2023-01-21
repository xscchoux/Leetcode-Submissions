class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        increase = decrease = 0
        
        for i in range(len(nums1)):
            diff = nums1[i] - nums2[i]
            if diff != 0:
                if k == 0 or diff%k:
                    return -1
                if diff > 0:
                    increase += diff//k
                else:
                    decrease += (-diff)//k
        
        if increase != decrease:
            return -1
    
        return increase