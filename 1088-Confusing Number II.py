class Solution:
    def confusingNumberII(self, n: int) -> int:

# DFS (5^log_10 N)
        mapping = {0:0, 1:1, 6:9, 8:8, 9:6}
        res = 0
        
        def dfs(num, rotateNum, digits):
            nonlocal res
            if num != rotateNum:
                res += 1
            
            for k, v in mapping.items():
                if num == 0 and k == 0:
                    continue
                if num*10 + k <= n:
                    dfs(num*10 + k, v*pow(10, digits-1) + rotateNum, digits+1)
        dfs(0, 0, 1)
        
        return res


# much better but harder:

        mapping = {"0":"0", "1":"1", "6":"9", "8":"8", "9":"6"}
        
        def canRotate(nStr):
            if not nStr:
                return 1
            res = 0
            
            res += sum(nStr[0] > nn for nn in mapping)*pow(5, len(nStr)-1)
            
            if nStr[0] in mapping:
                res += canRotate(nStr[1:])
            return res
        
        nStr = str(n)
        total = canRotate(nStr)
        
        def invalid(arr, l, r):
            res = 0
            if l > r:
                num = int("".join(arr))
                if num <= n:
                    return 1
                else:
                    return 0
            
            for k, v in mapping.items():
                arr[l], arr[r] = k, v
                if (len(arr) > 1 and arr[0] == "0") or (l == r and k != v):
                    continue
                res += invalid(arr, l+1, r-1)
            return res
        
        for length in range(1, len(nStr)+1):
            total -= invalid([0]*length, 0, length-1)
        
        return total