from sortedcontainers import SortedDict
class Solution(object):
    def maxDepthBST(self, order):
        """
        :type order: List[int]
        :rtype: int
        """
		# python way for binary treemap
        depths = SortedDict()
		# add dummy bounds to avoid extra ifs
        depths[float('-inf')] = 0
        
		# for every value find bounds and take the lowest depth + 1
		# put the value back to depths
        for x in order:
            i = depths.bisect_left(x)
            depths[x] = 1 + max(depths.values()[i - 1:i + 1])
        # return the maximum value so far
        return max(depths.values())