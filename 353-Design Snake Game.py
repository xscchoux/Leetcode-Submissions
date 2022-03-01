class SnakeGame(object):

    def __init__(self, width, height, food):
        """
        Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
        :type width: int
        :type height: int
        :type food: List[List[int]]
        """
        self.row = height
        self.col = width
        self.queue = collections.deque([[0,0]])
        self.food= collections.deque(food)
        self.score = 0
        
    def move(self, direction):
        """
        Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body.
        :type direction: str
        :rtype: int
        """
        tmp = self.queue[0][:]
        reserve = self.queue.pop()
        if direction == "U":
            tmp[0] -= 1
        elif direction == "L":
            tmp[1] -= 1
        elif direction == "R":
            tmp[1] += 1
        else:
            tmp[0] += 1
        
        if tmp in self.queue or tmp[0] < 0 or tmp[0] >= self.row or tmp[1] < 0 or tmp[1] >= self.col:
            return -1
        else:
            if self.food and tmp == self.food[0]:
                self.food.popleft()
                self.score += 1
                self.queue.append(reserve)
            self.queue.appendleft(tmp)
            return self.score