class Solution(object):
    def findAllRecipes(self, recipes, ingredients, supplies):
        """
        :type recipes: List[str]
        :type ingredients: List[List[str]]
        :type supplies: List[str]
        :rtype: List[str]
        """
        hmap = collections.defaultdict(list)
        indegree = collections.defaultdict(int)
        res = []
        recipeSet = set(recipes)
        
        for i in range(len(ingredients)):
            for ingredient in ingredients[i]:
                hmap[ingredient].append(recipes[i])
                indegree[recipes[i]] += 1
                indegree[ingredient] += 0
        
        queue = collections.deque(supplies)
        
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                if curr in recipeSet:
                    res.append(curr)
                for nxt in hmap[curr]:
                    indegree[nxt] -= 1
                    if indegree[nxt] == 0:
                        queue.append(nxt)
                        
        return res