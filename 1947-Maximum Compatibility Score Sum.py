class Solution(object):
    def maxCompatibilitySum(self, students, mentors):
        """
        :type students: List[List[int]]
        :type mentors: List[List[int]]
        :rtype: int
        """
        res = 0
        usedIndex = set()
        N = len(mentors)
        self.res = 0
        
        def calScore(a, b):
            res = 0
            for i in range(len(a)):
                if a[i] == b[i]:
                    res += 1
            return res
        
        def dfs(score, mentorNo):
            if mentorNo == N:
                self.res = max(score, self.res)
            for i in range(len(students)):
                if i not in usedIndex:
                    usedIndex.add(i)
                    dfs(score + calScore(students[i], mentors[mentorNo]), mentorNo+1)
                    usedIndex.remove(i)
        
        dfs(0, 0)
        return self.res