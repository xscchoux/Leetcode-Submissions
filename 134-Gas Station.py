class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """   
# O(n)
        if sum(cost) > sum(gas):
            return -1
        
        reach = 0
        start = 0
        
        for i in range(len(gas)):
            if reach + gas[i] < cost[i]:
                start = i+1
                reach = 0
            else:
                reach += gas[i] - cost[i]
        
        return start