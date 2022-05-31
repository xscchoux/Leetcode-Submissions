class Solution(object):
    def hasAllCodes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
# rolling hash, O(n)
        need = 1<<k
        got = [0]*need
        all_one = need-1
        rolling_hash = 0
        
        for i in range(len(s)):
            rolling_hash = ((rolling_hash << 1) & all_one) | int(s[i])
            if i >= k-1 and got[rolling_hash] == 0:
                got[rolling_hash] = 1
                need -= 1
                if need == 0:
                    return True
        return False