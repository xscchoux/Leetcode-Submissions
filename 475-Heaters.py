class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
# Time: O(mlogm + nlogn)
# Space: O(m), where m = len(heaters)

        houses.sort()
        heaters.sort()
        heaters = [float('-inf')] + heaters + [float('inf')]
        heaterIdx = 0
        radius = 0
        
        for house in houses:
            while house >= heaters[heaterIdx]:
                heaterIdx += 1
            res = min(heaters[heaterIdx]- house, house-heaters[heaterIdx-1])
            radius = max(radius, res)
        
        return radius