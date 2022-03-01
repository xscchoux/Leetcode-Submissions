class Solution:
    def findContestMatch(self, n: int) -> str:
        arr = [str(i) for i in range(1, n+1)]
        
        while len(arr) > 1:
            N = len(arr)
            for i in range(N//2):
                arr[i] = f"({arr[i]},{arr[N-i-1]})"
                arr.pop()
        
        return arr[0]