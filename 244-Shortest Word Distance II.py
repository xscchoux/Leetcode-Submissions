from collections import defaultdict
class WordDistance(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.hmap = defaultdict(list)
        for i in range(len(words)):
            self.hmap[words[i]].append(i)
        
    def shortest(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        list1 = self.hmap[word1]
        list2 = self.hmap[word2]
        res = float('inf')
        i, j = 0, 0
        while i <= len(list1)-1 and j <= len(list2)-1:
            res = min(res, abs(list2[j]-list1[i]))
            if list2[j] > list1[i]:
                i += 1
            else:
                j += 1

        return res