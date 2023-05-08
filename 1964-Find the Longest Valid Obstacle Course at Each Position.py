class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        arr = []
        res = []
        
        for i in range(len(obstacles)):
            ind = bisect_right(arr, obstacles[i])
            if ind == len(arr):
                arr.append(obstacles[i])
            else:
                arr[ind] = obstacles[i]
        
            res.append(ind+1)
        
        return res