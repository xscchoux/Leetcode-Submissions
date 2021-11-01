class Solution(object):
    def numberOfWeeks(self, milestones):
        """
        :type milestones: List[int]
        :rtype: int
        """
        mx = max(milestones)
        tot = sum(milestones)
        
        if mx <= tot//2:
            return tot
        else:
            return 2*(tot-mx) + 1