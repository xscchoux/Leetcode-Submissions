from collections import defaultdict
class Solution(object):
    def groupStrings(self, strings):
        """
        :type strings: List[str]
        :rtype: List[List[str]]
        """
        res = defaultdict(list)
        for s in strings:
            if len(s) == 1:
                res["single"].append(s)
            else:
                num = ""
                for c1, c2 in zip(s[:-1],s[1:]):
                    tmp = ord(c2) - ord(c1)
                    if tmp < 0:
                        tmp += 26
                    num += str(tmp)
                res[num].append(s)
        
        return res.values()