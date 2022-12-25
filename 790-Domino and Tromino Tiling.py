class Solution(object):
    def numTilings(self, n):
        """
        :type n: int
        :rtype: int
        """
# https://www.youtube.com/watch?v=S-fUTfqrdq8
        
# O(n) space
        full = [0]*(n+1)
        partial = [0]*(n+1)
        
        full[0] = 1
        full[1] = 1
        
        kMod = 1000000007
        
        for i in range(2, n+1):
            full[i] = (full[i-1] + full[i-2] + 2*partial[i-1])%kMod
            partial[i] = (partial[i-1] + full[i-2])%kMod
        
        return full[-1]
    
# O(1) space  
        f_curr = 1
        f_prev = 1
        p_curr = 0
        
        kMod = 1000000007
        
        for i in range(2, n+1):
            tmp = f_curr
            f_curr = (f_curr + f_prev + 2*p_curr)%kMod
            p_curr = (p_curr + f_prev)%kMod
            f_prev = tmp
            
        return f_curr