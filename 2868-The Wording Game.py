class Solution:
    def canAliceWin(self, a: List[str], b: List[str]) -> bool:
        maxString = [dict(), dict()]
        for c in a:
            maxString[0][c[0]] = c        
        for c in b:
            maxString[1][c[0]] = c
        
        @cache
        def dp(currFirst, nxt):   # A:0, B:1
            if currFirst in maxString[nxt^1] and maxString[nxt][currFirst] < maxString[nxt^1][currFirst]:
                if not dp(currFirst, nxt^1):
                    return True
            
            if ord(currFirst) + 1 <= ord('z') and chr(ord(currFirst) + 1) in maxString[nxt^1]:
                if not dp(chr(ord(currFirst) + 1), nxt^1):
                    return True
            
            return False # nxt cannot play on their turn
        
        return not dp(a[0][0], 0)