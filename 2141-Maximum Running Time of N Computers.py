class Solution(object):
    def maxRunTime(self, n, batteries):
        """
        :type n: int
        :type batteries: List[int]
        :rtype: int
        """
        left, right = min(batteries), sum(batteries)//n

        def checkOK(targetTime):
            totTime = 0
            totTarget = n*targetTime
            for battery in batteries:
                if battery > targetTime:
                    totTime += targetTime
                else:
                    totTime += battery
                if totTime >= totTarget:
                    return True
            return False
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if checkOK(mid):
                left = mid
            else:
                right = mid
        
        if checkOK(right):
            return right
        else:
            return left

# Sol 2

        batteries.sort()
        arr = batteries[len(batteries)-n:]
        excess = sum(batteries[:len(batteries)-n])
        
        for i in range(1, len(arr)):
            diff = arr[i] - arr[i-1]
            if excess >= diff*i:
                excess -= diff*i
            else:
                return arr[i-1] + excess//i
        
        return arr[-1] + excess//n