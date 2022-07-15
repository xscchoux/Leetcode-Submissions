class Solution(object):
    def minSumSquareDiff(self, nums1, nums2, k1, k2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k1: int
        :type k2: int
        :rtype: int
        """
        diff = []
        for i in range(len(nums1)):
            diff.append(abs(nums1[i]-nums2[i]))
        diff.append(0)
        diff.sort(reverse=True)
        
        ammo = k1 + k2
        res = 0
        
        for i in range(1, len(diff)):
            difference = diff[i-1]-diff[i]
            if difference*i < ammo:
                ammo -= difference*i
            else:
                q, r = divmod(ammo, i)
                for j in range(i):
                    if j < r:
                        res += (diff[i-1]-q-1)**2
                    else:
                        res += (diff[i-1]-q)**2
                for jj in range(i, len(diff)):
                    res += diff[jj]**2
                return res
        
        return res