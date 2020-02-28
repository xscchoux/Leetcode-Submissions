class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
# time complexity: O(n)
        newS = s.replace('10','1 0').replace('01','0 1').split(" ")
        res = sum(  [min(len(a),len(b)) for a, b in zip(newS, newS[1:])] )
        
        return res