from collections import defaultdict
class MagicDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hmap = defaultdict(list)

    def buildDict(self, dictionary):
        """
        :type dictionary: List[str]
        :rtype: None
        """
        for word in dictionary:
            self.hmap[len(word)].append(word)

    def search(self, searchWord):
        """
        :type searchWord: str
        :rtype: bool
        """
        for word in self.hmap[len(searchWord)]:
            count = 0
            for i in range(len(searchWord)):
                if word[i] != searchWord[i]:
                    count += 1
                    if count > 1:
                        break
            if count == 1:
                return True
        return False