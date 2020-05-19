class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        dict1 = [0]*26
        dict2 = [0]*26
        
        for i in range(len(s1)):
            dict1[ord(s1[i]) - ord('a')] += 1
        N = len(s1)
        for j in range(len(s2)):
            dict2[ord(s2[j]) - ord('a')] += 1
            
            if j >= N:
                dict2[ord(s2[j-N]) - ord('a')] -= 1
            
            if dict1 == dict2:
                return True
        return False