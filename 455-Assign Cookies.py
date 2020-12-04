class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        index_g = index_s = 0
        g.sort()
        s.sort()
        
        while index_g < len(g) and index_s < len(s):
            if s[index_s] < g[index_g]:
                index_s += 1
            else:
                index_s += 1
                index_g += 1
        
        return index_g