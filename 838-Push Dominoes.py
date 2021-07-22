class Solution(object):
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        N = len(dominoes)
        arr = [0]*N
        
        num = 0
        foundR = False
        
        for i in range(0, N):
            if dominoes[i] == "R":
                num = 1
                arr[i] = num
                foundR = True
            elif foundR and dominoes[i] == ".":
                num*= 0.5
                arr[i] = num
            else:
                foundR = False
        
        
        num = 0
        foundL = False
        
        for i in range(N-1, -1, -1):
            if dominoes[i] == "L":
                num = -1
                arr[i] = num
                foundL = True
            elif foundL and dominoes[i] == ".":
                num *= 0.5
                arr[i] += num
            else:
                foundL = False
        
        for i in range(N):
            if arr[i] > 0:
                arr[i] = "R"
            elif arr[i] == 0:
                arr[i] = "."
            else:
                arr[i] = "L"

        return "".join(arr)