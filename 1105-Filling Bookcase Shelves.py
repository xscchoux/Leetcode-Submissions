class Solution(object):
    def minHeightShelves(self, books, shelfWidth):
        """
        :type books: List[List[int]]
        :type shelfWidth: int
        :rtype: int
        """
        n = len(books)
        dp = [float('inf')]*(n+1)
        dp[0] = 0
        
        for i in range(1, n+1):
            currWidth = 0
            H = 0
            j = i-1
            while j >= 0 and currWidth + books[j][0] <= shelfWidth:
                currWidth += books[j][0]
                H = max(H, books[j][1])
                dp[i] = min(dp[i], dp[j] + H)
                j -= 1
        
        return dp[n]