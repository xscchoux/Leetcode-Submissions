class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
# Time complexity :O(n)  Space complexity: O(n)
# solution 1
        strlist = s.split(" ")
        res = []
        for i in range(len(strlist)-1,-1,-1):
            if not strlist[i]:
                continue
            res.append(strlist[i])
        return " ".join(res)

# solution2 
        tmp = s.split()
        return " ".join(tmp[::-1])