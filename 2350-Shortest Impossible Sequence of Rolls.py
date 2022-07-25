class Solution(object):
    def shortestSequence(self, rolls, k):
        """
        :type rolls: List[int]
        :type k: int
        :rtype: int
        """
        count = set()
        res = 0

        for i in range(len(rolls)):
            count.add(rolls[i])
            if len(count) == k:
                res += 1
                count.clear()
        
        return res+1