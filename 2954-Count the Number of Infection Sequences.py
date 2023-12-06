# S! / (len[1]! * len[2]! * ... * len[m]!) * 2^(len[1]-1) * 2^(len[2]-1) * ... * 2^(len[m]-1)
# S is the total length of all segments of non-infected children
# There are S! / (len[1]! * len[2]! * ... * len[m]!) to rearrange by groups
# There are 2^(len[i]-1) possible arrangements for each group i

factorial = [1]*100001
kMod = 10**9+7

for i in range(2, 100001):
    factorial[i] = (i*factorial[i-1])%kMod


class Solution:
    def numberOfSequence(self, n: int, sick: List[int]) -> int:
        kMod = 10**9+7
        
        segment = []
        
        segment.append(sick[0])
        for a, b in zip(sick, sick[1:]):
            segment.append(b-a-1)
        segment.append(n-sick[-1]-1)

        res = factorial[sum(segment)]
        
        for i, length in enumerate(segment):
            res = ( res*pow(factorial[length], -1, kMod) )%kMod
            
            if length >= 2 and i not in (0, len(segment)-1):
                res = ( res*pow(2, length-1, kMod) )%kMod
        
        return res