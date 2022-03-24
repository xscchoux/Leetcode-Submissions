class Solution(object):
    def minimumHealth(self, damage, armor):
        """
        :type damage: List[int]
        :type armor: int
        :rtype: int
        """
        tot = sum(damage)
        maxDamage = max(damage)
        
        if armor >= maxDamage:
            return tot - maxDamage + 1
        else:
            return tot - armor + 1