class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        
        for i in range(len(strs[0])):
            curr = strs[0][i]
            for j in range(1, len(strs)):
                if i == len(strs[j]) or curr != strs[j][i]:
                    return strs[0][:i]
        
        return strs[0]