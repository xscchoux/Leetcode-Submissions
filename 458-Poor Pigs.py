class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        """
        :type buckets: int
        :type minutesToDie: int
        :type minutesToTest: int
        :rtype: int
        """
        # state^x >= buckets
        states = minutesToTest//minutesToDie + 1
        return int(math.ceil(math.log(buckets)/math.log(states)))