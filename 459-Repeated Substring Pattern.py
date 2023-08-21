class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
# https://leetcode.com/problems/repeated-substring-pattern/discuss/94334/Easy-python-solution-with-explaination
        t = s + s
        if s in t[1:-1]:
            return True
        return False