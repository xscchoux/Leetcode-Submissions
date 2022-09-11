class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        
        @cache
        def countPower(num):
            if num == 1:
                return 0
            count = 0
            if num%2 == 1:
                count = 1 + countPower(3*num+1)
            else:
                count = 1 + countPower(num//2)
            return count
        
        arr = []
        for x in range(lo, hi+1):
            arr.append((countPower(x), x))
            
        arr.sort()
        
        return arr[k-1][1]