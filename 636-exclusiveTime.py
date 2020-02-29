class Solution(object):
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
# time complexity: O(n)
        res = [0]*n
        stack = []
        for log in logs:
            id, condition, time = log.split(":")
            id, time = int(id), int(time)
            if condition == "start":
                if stack:
                    res[stack[-1]] += time-prev
                stack.append(id)
                prev = time
            else:
                res[stack[-1]] += time-prev+1
                prev = time+1
                stack.pop()
        return res