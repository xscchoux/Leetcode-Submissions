from collections import defaultdict, deque
class Solution(object):
    def sequenceReconstruction(self, org, seqs):
        """
        :type org: List[int]
        :type seqs: List[List[int]]
        :rtype: bool
        """
# check if there is only one result using topological sort

# construct the graph
        graph = defaultdict(set)
        for seq in seqs:
            for s in seq:
                graph[s] = set()
                
        for seq in seqs:
            for s, t in zip(seq[:-1], seq[1:]):
                graph[s].add(t)

# calculate indegree for all nodes
        indegree = {key:0 for key in graph}
        for key, val in graph.items():
            for xx in val:
                indegree[xx] += 1
                
# put nodes with indegree == 0 into the queue
        queue = deque([])
        nodes = indegree.keys()
        for node in nodes:
            if indegree[node] == 0:
                del indegree[node]
                queue.append(node)

# if len(queue) != 1, return False
        res = []
        while queue:
            size = len(queue)
            if size != 1:
                return False
            for _ in range(size):
                curr = queue.popleft()
                res.append(curr)
                for childNode in graph[curr]:
                    indegree[childNode] -= 1
                    if indegree[childNode] == 0:
                        del indegree[childNode]
                        queue.append(childNode)
        # when "res" doesn't contain all the node in the seqs
        if len(res) < len(graph):
            return False
        return org == res