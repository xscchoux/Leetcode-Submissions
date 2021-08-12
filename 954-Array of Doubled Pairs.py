class Solution(object):
    def canReorderDoubled(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        hmap = collections.Counter(arr)
        
        for num in sorted(arr):
            if hmap[num] > 0:
                if num >= 0:
                    if hmap[num*2] > 0:
                        hmap[num] -= 1
                        hmap[num*2] -= 1
                    else:
                        return False
                else:
                    if hmap[num/2.0] > 0:
                        hmap[num] -= 1
                        hmap[num/2.0] -= 1
                    else:
                        return False

        return True