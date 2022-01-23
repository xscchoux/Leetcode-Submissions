class Solution(object):
    def numberOfWays(self, corridor):
        """
        :type corridor: str
        :rtype: int
        """
        kMod = 1000000007
        seats = [i for i, x in enumerate(corridor) if corridor[i] == "S"]
        
        if len(seats) < 2 or len(seats)%2 == 1:
            return 0
        
        tot = 1
        for i in range(2, len(seats), 2):
            tot = tot*(seats[i]-seats[i-1])%kMod
            # print(tot)
            
        return tot