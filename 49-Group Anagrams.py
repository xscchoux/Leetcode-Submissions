from collections import defaultdict
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
# time complexity: O(Nklogk)  N: length of strs, k: length of words
        hmap = defaultdict(list)
        for string in strs:
            stringList = list(string)
            newString = "".join(sorted(stringList))
            hmap[newString].append(string)

        return hmap.values()