class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        people.sort(key = lambda x:(-x[0], x[1]))
        
        for p in people:
            res.insert(p[1], p)
        
        return res