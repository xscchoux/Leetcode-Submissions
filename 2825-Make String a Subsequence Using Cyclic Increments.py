class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        idx2 = 0
        N = len(str2)
        for i in range(len(str1)):
            if str2[idx2] == str1[i] or chr( (ord(str1[i]) - ord('a') + 1)%26 + ord('a')) == str2[idx2]:
                idx2 += 1
            if idx2 == N:
                return True

        return False