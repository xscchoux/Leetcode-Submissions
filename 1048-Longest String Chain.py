from collections import deque
class Solution(object):
    def longestStrChain(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
# first visit (BFS)
#         wordSet = set(words)
#         used = set()
#         words.sort(key = lambda x: -len(x))
#         res = 1
        
#         for word in words:
#             if word in used:
#                 continue
#             queue = deque([(word, 1)])
#             used.add(word)
#             while queue:
#                 for _ in range(len(queue)):
#                     curr, step = queue.popleft()
#                     res = max(res, step)
#                     for i in range(len(curr)):
#                         newWord = curr[:i] + curr[i+1:]
#                         if newWord in wordSet and newWord not in used:
#                             used.add(newWord)
#                             queue.append([newWord, step+1])
#         return res
        
# DP, O(NlogN + N*L^2)
# N: length of the array, L:length of the longest word
        res = 1
        words.sort(key = len)
        dp = dict()
        
        for word in words:
            dp[word] = 1
        
        for word in words:
            for i in range(len(word)):
                prev = word[:i] + word[i+1:]
                if prev in dp:
                    dp[word] = max(dp[word], dp[prev] + 1)
            res = max(res, dp[word])            
        
        return res