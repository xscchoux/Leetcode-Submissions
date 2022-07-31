class Solution(object):
    def maximumGroups(self, grades):
        """
        :type grades: List[int]
        :rtype: int
        """
        grades.sort()
        res = 0
        currTot = currPeople = 0
        runningTot = runningPeople = 0
        
        for i, val in enumerate(grades):
            runningTot += val
            runningPeople += 1
            if runningTot > currTot and runningPeople > currPeople:
                res += 1
                currTot = runningTot
                currPeople = runningPeople
                runningPeople = runningTot = 0
        return res