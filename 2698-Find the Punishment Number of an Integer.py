def canPartition(num):
    squareStr = str(num*num)
    for state in range(1<<(len(squareStr)-1)):
        p = [""]
        for j, c in enumerate(squareStr):
            p[-1] += c
            if state & (1<<j):
                p.append("")
        if sum(map(int, p)) == num:
            return True
    return False

allNum = [i*i if canPartition(i) else 0 for i in range(1001)]

class Solution:
    def punishmentNumber(self, n: int) -> int:
        return sum(allNum[i] for i in range(n+1))
    
    
# naive backtracking

#         def divide(numStr, expect):
#             if not numStr and expect == 0:
#                 return True
#             for j in range(1, len(numStr)+1):
#                 leftNum = int(numStr[:j])
#                 if leftNum > expect:
#                     break
#                 if expect >= leftNum and divide(numStr[j:], expect-leftNum):
#                     return True
#             return False
        
#         res = 1
#         for i in range(2, n+1):
#             squareStr = str(i*i)
#             if divide(squareStr, i):
#                 res += i*i
                         
#         return res