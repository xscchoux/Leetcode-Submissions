from collections import Counter
class Solution(object):
    def sortString(self, s):
        """
        :type s: str
        :rtype: str
        """
        hmap = Counter(s)
        res = ""
        while len(res) < len(s):
            for char in 'abcdefghijklmnopqrstuvwxyz':
                if hmap[char]:
                    res += char
                    hmap[char] -= 1
                    
            for char in 'zyxwvutsrqponmlkjihgfedcba':
                if hmap[char]:
                    res += char
                    hmap[char] -= 1
        
        return res