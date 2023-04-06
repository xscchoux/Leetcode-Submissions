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




# add cache
class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        res = []
        cache = dict()
        
        for num in spells:
            if num in cache:
                res.append(cache[num])
                continue

            left, right = 0, len(potions)-1
            curr = 0
            while left + 1 < right:
                mid = left + (right-left)//2
                if num*potions[mid] >= success:
                    right = mid
                else:
                    left = mid
            if num*potions[left] >= success:
                curr = len(potions) - left
            elif num*potions[right] >= success:
                curr = len(potions) - right
                
            cache[num] = curr
            res.append(curr)
            
        return res