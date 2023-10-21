class Solution(object):
    def maximumBooks(self, books):
        """
        :type books: List[int]
        :rtype: int
        """
        dp = [0]*len(books)
        stack = []
        
        for i in range(len(books)):
            if books[i] == 0:
                dp[i] = 0
                stack.append(i)
                continue
                
            if i == 0:
                dp[i] = books[i]
            else:
                while stack:
                    j = stack[-1]
                    if books[j] >= books[i] - (i - j):
                        stack.pop()
                    else:
                        break
                tot = 0
                if not stack:
                    if books[i] - i > 0:
                        tot += (books[i]+books[i]-i)*(i+1)//2
                    else:
                        tot += (books[i]+1)*books[i]//2
                    dp[i] = tot
                else:
                    if i-j+1 > books[i]:
                        tot += (books[i]+1)*books[i]//2
                    else:
                        tot += (books[i]+books[i]-(i-j-1))*(i-j)//2
                    dp[i] = dp[j] + tot
                # Or we can simply set j = -1 when stack is empty
            stack.append(i)
        return max(dp)


# Second visited

        # dp[i] : maximum number of books you can take from 0 to i
        # if books[j] < books[i] - (i-j) => books[j] - j < books[i] - i, dp[i] = dp[j] + calculateSum(j+1, i)
        
        N = len(books)
        dp = [0]*N
        stack = []
        
        def calculateSum(start, end):
            count = min(books[end], end-start+1)
            return (books[end] + (books[end]-count+1))*count//2
        
        for i in range(N):
            while stack and books[stack[-1]] - stack[-1] >= books[i] - i:
                stack.pop()
            
            if not stack:
                dp[i] = calculateSum(0, i)
            else:
                j = stack[-1]
                dp[i] = dp[j] + calculateSum(j+1, i)
        
            stack.append(i)
            
        return max(dp)