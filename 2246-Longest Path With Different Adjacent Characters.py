class Solution(object):
    def longestPath(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: int
        """
        graph = collections.defaultdict(list)
        for i in range(len(parent)):
            graph[parent[i]].append(i)
        
        memo = dict()
        
        def dfs(node):
            if node in memo:
                return memo[node]
            curr = 1
            for child in graph[node]:
                if s[child] == s[node]:
                    continue
                curr = max(curr, dfs(child)+1)
            memo[node] = curr
            return curr
        
        res = 0
        for i in range(len(s)):
            first = second = 0
            for nxt in graph[i]:
                if s[nxt] == s[i]:
                    continue
                tmp = dfs(nxt)
                if tmp > first:
                    second = first
                    first = tmp
                elif tmp > second:
                    second = tmp
            res = max(res, first + second + 1)
        
        return res