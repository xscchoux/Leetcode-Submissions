class Solution:
    def canAliceWin(self, a: List[str], b: List[str]) -> bool:
# https://leetcode.com/problems/the-wording-game/discuss/4097898/Python-3-Only-lexicographically-largest-for-each-initial-letter
        maxString = [dict(), dict()]
        for c in a:
            maxString[0][c[0]] = c        
        for c in b:
            maxString[1][c[0]] = c
        
        @cache
        def dp(currFirst, currIdx):   # A:0, B:1
            if currFirst in maxString[currIdx^1] and maxString[currIdx][currFirst] < maxString[currIdx^1][currFirst]:
                if not dp(currFirst, currIdx^1):
                    return True
            
            if ord(currFirst) + 1 <= ord('z') and chr(ord(currFirst) + 1) in maxString[currIdx^1]:
                if not dp(chr(ord(currFirst) + 1), currIdx^1):
                    return True
            
            return False # nxt cannot play on their turn
        
        return not dp(a[0][0], 0)