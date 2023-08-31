class Solution:
    def maximumCoins(self, heroes: List[int], monsters: List[int], coins: List[int]) -> List[int]:
        arr = []
        for m, c in zip(monsters, coins):
            arr.append([m, c])
        arr.sort()
        for i in range(1, len(arr)):
            arr[i][1] += arr[i-1][1]
        
        res = []
        for hero in heroes:
            left, right = 0, len(monsters) - 1
            while left + 1 < right:
                mid = left + (right-left)//2
                if hero >= arr[mid][0]:
                    left = mid
                else:
                    right = mid
            if hero >= arr[right][0]:
                res.append(arr[right][1])
            elif hero >= arr[left][0]:
                res.append(arr[left][1])
            else:
                res.append(0)
        return res
        