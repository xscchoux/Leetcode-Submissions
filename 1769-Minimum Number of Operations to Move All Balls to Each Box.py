class Solution(object):
    def minOperations(self, boxes):
        """
        :type boxes: str
        :rtype: List[int]
        """
        N = len(boxes)
        res = [0]*N
        
        leftCount = leftStep = 0
        for i in range(1, N):
            if boxes[i-1] == "1":
                leftCount += 1
            leftStep += leftCount
            res[i] += leftStep
        
        rightCount = rightStep = 0
        for j in range(N-2, -1, -1):
            if boxes[j+1] == "1":
                rightCount += 1
            rightStep += rightCount
            res[j] += rightStep
        
        return res