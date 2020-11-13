class Solution(object):
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        people.sort()
        res = 0
        start = 0
        end = len(people)-1
        
        while start <= end:
            res += 1
            if people[end] + people[start] <= limit:
                start += 1
                end -= 1
            else:
                end -= 1
        
        return res