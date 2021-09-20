from heapq import heappush, heappop
class Solution(object):
    def longestDiverseString(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: str
        """
# O(n)
        toPut = sorted([(a, "a"), (b, "b"), (c, "c")])
        res = ""
        
        def find(index, count):
            num, char = toPut[index]
            toGet = min(num, count)
            toPut[index] = (num-toGet, char)
            toPut.sort()
            return char*toGet
        
        res += find(2, 2)

        while toPut[2][0] > 0:
            if res[-1] != toPut[2][1]:
                res += find(2, 2)
            elif toPut[1][0] > 0:
                res += find(1, 1)
            else:
                break
        
        return res
    
# O(n), heap
# Append the 2 chars with most occurences first (if only 1 letter, put 1)
# In the situation where two highest-count letters are already used previously, we find the second highest char and we add one char

        pq = []
        res = ""
        
        if a!=0:
            heappush(pq, (-a, "a"))
        if b!=0:
            heappush(pq, (-b, "b"))
        if c!=0:
            heappush(pq, (-c, "c"))
        
        while pq:
            currNum, char = heappop(pq)
            if res and char == res[-1] and char == res[-2] and pq:
                currNum2, char2 = heappop(pq)
                res += char2
                currNum2 += 1
                if currNum2 != 0:
                    heappush(pq, (currNum2, char2))
                heappush(pq, (currNum, char))
            else:
                if res and res[-1] == char:
                    return res
                toGet = min(2, -currNum)
                res += char*toGet
                currNum += toGet
                if currNum != 0:
                    heappush(pq, (currNum, char))
                
        return res