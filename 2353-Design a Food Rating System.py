from sortedcontainers import SortedList
class FoodRatings(object):

    def __init__(self, foods, cuisines, ratings):
        """
        :type foods: List[str]
        :type cuisines: List[str]
        :type ratings: List[int]
        """
        self.cuisine2food = collections.defaultdict(SortedList)
        self.food2rating = dict()
        for food, cuisine, rating in zip(foods, cuisines, ratings): 
            self.cuisine2food[cuisine].add((-rating, food))
            self.food2rating[food] = (cuisine, rating)

    def changeRating(self, food, newRating):
        """
        :type food: str
        :type newRating: int
        :rtype: None
        """
        cuisine, rating = self.food2rating[food]
        self.cuisine2food[cuisine].discard((-rating, food))
        
        self.food2rating[food] = (cuisine, newRating)
        self.cuisine2food[cuisine].add((-newRating, food))
        
    def highestRated(self, cuisine):
        """
        :type cuisine: str
        :rtype: str
        """
        return self.cuisine2food[cuisine][0][1]
    

# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)