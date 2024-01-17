class Solution:
    def numWays(self, s: str) -> int:
        cnt = s.count("1")
        if cnt%3 != 0:
            return 0
        if cnt == 0:
            return (len(s)-1)*(len(s)-2)//2%(10**9+7)
        num = cnt//3
        
        tmp1 = tmp2 = 0
        idx1 = idx2 = 0
        for i in range(len(s)):
            if s[i] == "1":
                tmp1 += 1
            if tmp1 == num:
                idx1 = i
                break
        
        for i in range(len(s)-1, -1, -1):
            if s[i] == "1":
                tmp2 += 1
            if tmp2 == num:
                idx2 = i
                break
        
        count1 = count2 = 0
        for i in range(idx1+1, len(s)):
            if s[i] == "0":
                count1+= 1
            else:
                break

        for i in range(idx2-1, -1, -1):
            if s[i] == "0":
                count2 += 1
            else:
                break
        
        return ((count1+1)*(count2+1))%(10**9+7)