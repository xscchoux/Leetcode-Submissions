class Solution(object):
    def successfulPairs(self, spells, potions, success):
        """
        :type spells: List[int]
        :type potions: List[int]
        :type success: int
        :rtype: List[int]
        """
        potions.sort()
        res = [0]*len(spells)

        for i in range(len(spells)):
            curr = spells[i]
            left, right = 0, len(potions)-1
            while left + 1 < right:
                mid = left + (right-left)//2
                if curr*potions[mid] >= success:
                    right = mid
                else:
                    left = mid
            if curr*potions[left] >= success:
                res[i] = len(potions) - left
            elif curr*potions[right] >= success:
                res[i] = len(potions) - right
                
        return res