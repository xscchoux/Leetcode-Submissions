class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        arr = list(str(n))
        if len(arr) <= 1:
            return -1
        
        for i in range(len(arr)-2, -1, -1):
            if int(arr[i]) < int(arr[i+1]):
                index = len(arr)-1
                while arr[index] <= arr[i]:
                    index-=1
                arr[i], arr[index] = arr[index], arr[i]
                arr[i+1:] = arr[i+1:][::-1]
                break
            if i == 0:
                return -1
            
        res = int("".join(arr))
        if res > 2147483647:
            return -1
        else:
            return res