from sortedcontainers import SortedList
class TodoList:

    def __init__(self):
        self.hmap = collections.defaultdict(SortedList) # id:tasks
        self.tag = collections.defaultdict(set) # tag:uncompleted task
        self.task = [["", False] for _ in range(101)]  # [(str) taskDescription, (bool) completed]
        self.taskId = 0

    def addTask(self, userId: int, taskDescription: str, dueDate: int, tags: List[str]) -> int:
        self.taskId += 1
        self.hmap[userId].add((dueDate, self.taskId))
        for tag in tags:
            self.tag[tag].add(self.taskId)
        self.task[self.taskId][0] = taskDescription
        return self.taskId
        
    def getAllTasks(self, userId: int) -> List[str]:
        arr = []
        for _, tId in self.hmap[userId]:
            if not self.task[tId][1]:
                arr.append(self.task[tId][0])
        return arr

    def getTasksForTag(self, userId: int, tag: str) -> List[str]:
        arr = []
        tagSet = self.tag[tag]
        for _, tId in self.hmap[userId]:
            if tId in tagSet and not self.task[tId][1]:
                arr.append(self.task[tId][0])
        return arr

    def completeTask(self, userId: int, taskId: int) -> None:
        for _, tId in self.hmap[userId]:
            if tId == taskId:
                if not self.task[tId][1]:
                    self.task[tId][1] = True
            

# Your TodoList object will be instantiated and called as such:
# obj = TodoList()
# param_1 = obj.addTask(userId,taskDescription,dueDate,tags)
# param_2 = obj.getAllTasks(userId)
# param_3 = obj.getTasksForTag(userId,tag)
# obj.completeTask(userId,taskId)