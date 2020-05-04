from collections import Counter
import heapq
class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
# time complexity: O(n + klog(n))
# space complexity: O(n)
        count = Counter(words)
        return heapq.nsmallest(k, count.keys(), key=lambda x: (-count[x],x))