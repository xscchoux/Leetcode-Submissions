class Solution(object):
    def nextPalindrome(self, num):
        """
        :type num: str
        :rtype: str
        """
        N = len(num)
        
        start = -1
        for i in range(N//2-2, -1, -1):
            if num[i] < num[i+1]:
                start = i
                break
        
        if start == -1:
            return ""
        
        arr = list(num[:N//2])
        for j in range(len(arr)-1, start, -1):
            if arr[j] > arr[start]:
                end = j
                break

        arr[start], arr[end] = arr[end], arr[start]
        arr[start+1:] = arr[start+1:][::-1]
        
        mid = [] if N%2 == 0 else [num[N//2]]
        
        return "".join(arr + mid + arr[::-1])