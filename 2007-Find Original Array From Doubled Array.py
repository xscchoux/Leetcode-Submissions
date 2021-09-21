class Solution(object):
    def findOriginalArray(self, changed):
        """
        :type changed: List[int]
        :rtype: List[int]
        """
        if len(changed) % 2:
            return []
        
        changed.sort()
        passed = collections.deque([])
        res = []
        
        for xx in changed:
            if xx%2 == 0 and passed and xx//2 == passed[0]:
                res.append(xx//2)
                passed.popleft()
            else:
                passed.append(xx)
                
        if len(passed) == 0:
            return res
        
        return []