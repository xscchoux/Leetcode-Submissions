class Solution:
    def fixedRatio(self, s: str, num1: int, num2: int) -> int:
        
# num1/num2 = count1/count2 => num1*count2 = num2*count1
# Just find subarrays in which num1*count2 - num2*count1 == 0
        hmap = collections.defaultdict(int)
        curr = res = 0
        hmap[0] = 1
        
        for i in range(len(s)):
            if s[i] == "0":
                curr -= num2
            else:
                curr += num1
            res += hmap[curr]
            hmap[curr] += 1
        
        return res