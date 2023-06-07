class Solution:
    def countGoodNumbers(self, n: int) -> int:
        # even:  0 2 4 6 8
        # prime: 2 3 5 7

# first try
        kMod = 10**9+7
        @cache
        def cal(boolean, n):
            if n == 1:
                if not boolean:
                    return 4
                else:
                    return 5
            if n - 2*(n//2) == 1:
                if (n//2)%2 == 1:
                    return (cal(boolean, n//2)*cal(not boolean, 1)*cal(boolean, n//2))%kMod
                else:
                    return (cal(boolean, n//2)*cal(boolean, 1)*cal(not boolean, n//2))%kMod
            else:
                if (n//2)%2 == 0:
                    return (cal(boolean, n//2)*cal(boolean, n//2))%kMod
                else:
                    return (cal(boolean, n//2)*cal(not boolean, n//2))%kMod
                
        return cal(True, n)  # true -> start with 5
    
# fast and clean
        kMod = 10**9+7
        even = n//2 + n%2
        odd = n//2
        
        return pow(5, even, kMod)*pow(4, odd, kMod)%kMod