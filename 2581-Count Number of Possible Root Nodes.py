class Solution:
    def rootCount(self, edges: List[List[int]], guesses: List[List[int]], k: int) -> int:
# https://www.youtube.com/watch?v=Dq_c2XZV1jc      
        self.res = 0
        hmap = collections.defaultdict(list)
        for u, v in edges:
            hmap[u].append(v)
            hmap[v].append(u)

        guessSet = collections.defaultdict(set)
        for u, v in guesses:
            guessSet[u].add(v)
        
        # Start by using 0 as root
        def dfs(node, parent):
            tot = 0
            for nxt in hmap[node]:
                if nxt != parent:
                    if nxt in guessSet[node]:
                        tot += 1
                    tot += dfs(nxt, node)
            return tot
                
        matched = dfs(0, -1)
        
        def dfs2(node, parent, count):
            if count >= k:
                self.res += 1
            for nxt in hmap[node]:
                if nxt != parent:
                    tmp = count
                    if nxt in guessSet[node]:
                        tmp -= 1
                    if node in guessSet[nxt]:
                        tmp += 1
                    dfs2(nxt, node, tmp)

        dfs2(0, -1, matched)
        
        return self.res