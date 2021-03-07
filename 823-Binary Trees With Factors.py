class Solution(object):
    def numFactoredBinaryTrees(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        hmap = dict()
        arr.sort()
        res = 0
        for i in range(len(arr)):
            hmap[arr[i]] = 1
            for j in range(i):
                if arr[i]%arr[j] == 0 and arr[i]/arr[j] in hmap:
                    hmap[arr[i]] += hmap[arr[j]]*hmap[arr[i]/arr[j]]
            res += hmap[arr[i]]%(10**9+7)
        
        return res%(10**9+7)