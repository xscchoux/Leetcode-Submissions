class Solution(object):
    def minimumBuckets(self, street):
        """
        :type street: str
        :rtype: int
        """
# We should place the bucket on the right side - so that bucket can be (potentially) used by the next house
        res = 0
        street = list(street)
        for i in range(len(street)):
            if street[i] == "H":
                if i>0 and street[i-1] == "B":
                    continue
                if i < len(street)-1 and street[i+1] == ".":
                    street[i+1] = "B"
                    res += 1
                elif i > 0 and street[i-1] == ".":
                    street[i-1] = "B"
                    res += 1
                else:
                    return -1
                
        return res