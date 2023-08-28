class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        extraGroupID = m
        
        for i, groupID in enumerate(group):
            if groupID == -1:
                group[i] = extraGroupID
                extraGroupID += 1

        indegreeItem = [0]*n
        indegreeGroup = [0]*(extraGroupID)
        groupGraph = defaultdict(set)
        itemGraph = defaultdict(set)
        
        # contruct itemGraph, groupGraph, indegreeItem and indegreeGroup
        for i, array in enumerate(beforeItems):
            for item in array:
                itemGraph[item].add(i)
                indegreeItem[i] += 1
                if group[i] != group[item]:
                    groupGraph[group[item]].add(group[i])
        
        for k, v in groupGraph.items():
            for groupID in v:
                indegreeGroup[groupID] += 1
        
        # Topogical sort for items
        itemArr = []
        ItemQueue = deque([i for i in range(len(indegreeItem)) if indegreeItem[i] == 0])
        
        while ItemQueue:
            for _ in range(len(ItemQueue)):
                curr = ItemQueue.popleft()
                itemArr.append(curr)
                for nxt in itemGraph[curr]:
                    indegreeItem[nxt] -= 1
                    if indegreeItem[nxt] == 0:
                        ItemQueue.append(nxt)

        if len(itemArr) != n:
            return []

        # Topogical sort for groups
        groupArr = []
        GroupQueue = deque([i for i in range(len(indegreeGroup)) if indegreeGroup[i] == 0])
        while GroupQueue:
            for _ in range(len(GroupQueue)):
                curr = GroupQueue.popleft()
                groupArr.append(curr)
                for nxt in groupGraph[curr]:
                    indegreeGroup[nxt] -= 1
                    if indegreeGroup[nxt] == 0:
                        GroupQueue.append(nxt)            

        if len(groupArr) != extraGroupID:
            return []
        
        # Differentiate items by the groups they belong to
        groupToItem = defaultdict(list)
        
        for item in itemArr:
            groupToItem[group[item]].append(item)
        
        res = []
        for g in groupArr:
            res.extend(groupToItem[g])
            
        return res
        