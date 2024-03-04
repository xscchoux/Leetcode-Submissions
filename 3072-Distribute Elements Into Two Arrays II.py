from sortedcontainers import SortedList
class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        sl1, sl2 = SortedList([nums[0]]), SortedList([nums[1]])
        arr1, arr2 = [nums[0]], [nums[1]]
        
        for num in nums[2:]:
            if len(arr1) - sl1.bisect_left(num+1) > len(arr2) - sl2.bisect_left(num+1):
                sl1.add(num)
                arr1.append(num)
            elif len(arr1) - sl1.bisect_left(num+1) < len(arr2) - sl2.bisect_left(num+1):
                sl2.add(num)
                arr2.append(num)
            else:
                if len(arr1) <= len(arr2):
                    sl1.add(num)
                    arr1.append(num)
                else:
                    sl2.add(num)
                    arr2.append(num)
        
        return arr1+arr2