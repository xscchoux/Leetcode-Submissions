class Solution(object):
    def canArrange(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: bool
        """
        if len(arr)%2 != 0:
            return False
        
        hmap = dict()
        for i in range(len(arr)):
            hmap[arr[i]%k] = hmap.get(arr[i]%k, 0) + 1
        
        if 0 in hmap:
            if hmap[0]%2 != 0:
                return False
            del hmap[0]
        
        for key in hmap:
            if k-key not in hmap:
                return False
            if hmap[key] != hmap[k-key]:
                return False
        return True