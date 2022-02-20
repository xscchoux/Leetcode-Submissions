class Solution(object):
    def minSwaps(self, s):
        """
        :type s: str
        :rtype: int
        """
# https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/discuss/1390193/Python-Greedy-O(n)-explained
        score = 0
        minScore = len(s)
        
        for c in s:
            if c == "[":
                score += 1
            else:
                score -= 1
                minScore = min(minScore, score)
                
        return (-minScore+1)//2