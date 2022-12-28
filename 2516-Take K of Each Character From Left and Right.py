class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        
# first try, binary search
        count = collections.Counter(s)
        if any(count[v] < k for v in 'abc'):
            return -1
        
        def isOK(mid):
            hmap = count.copy()
            for i in range(mid):
                hmap[s[i]] -= 1
            if all(hmap[v] >= k for v in 'abc'):
                return True
            
            for i in range(mid, len(s)):
                hmap[s[i]] -= 1
                hmap[s[i-mid]] += 1
                if all(hmap[v] >= k for v in 'abc'):
                    return True
                
            return False
        
        left, right = 0, len(s)
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                left = mid
            else:
                right = mid
        
        if isOK(right):
            return len(s)-right
        else:
            return len(s)-left
        
# sliding window, O(n)
# https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/discuss/2948183/Python-clean-12-line-sliding-window-solution-with-explanation

        limit = collections.Counter(s)
        for c in 'abc':
            limit[c] -= k
            if limit[c] < 0:
                return -1
        
        curr = collections.defaultdict(int)
        left = 0
        res = 0
        
        for i in range(len(s)):
            curr[s[i]] += 1
            while curr[s[i]] > limit[s[i]]:
                curr[s[left]] -= 1
                left += 1
            res = max(res, i - left + 1)
            
        return len(s) - res