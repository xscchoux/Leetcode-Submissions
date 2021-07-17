class Solution(object):
    def threeEqualParts(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        ones = arr.count(1)
        if ones == 0:
            return [0,2]
        if ones%3:
            return [-1,-1]
        
        n = len(arr)
        p1 = p2 = p3 = 0
        target = ones//3
        cnt = 0
        
        for i in range(len(arr)):
            if arr[i] == 1:
                if cnt == 0:
                    p1 = i
                elif cnt == target:
                    p2 = i
                elif cnt == 2*target:
                    p3 = i
                cnt += 1
        
        oldP2 = p2
        oldP3 = p3
        while p1 < oldP2 and p2 < oldP3 and p3 < n:
            if arr[p1] != arr[p2] or arr[p2] != arr[p3]:
                return [-1,-1]
            else:
                p1+=1
                p2+=1
                p3+=1
        
        if p3<n:
            return [-1,-1]
        else:
            return [p1-1, p2]