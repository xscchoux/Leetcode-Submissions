from heapq import heappush, heappop
class Twitter(object):

    def __init__(self):
        self.followed = collections.defaultdict(set)
        self.tweets = collections.defaultdict(list)
        self.time = 0

    def postTweet(self, userId, tweetId):
        """
        :type userId: int
        :type tweetId: int
        :rtype: None
        """
        self.time -= 1
        self.tweets[userId].append((self.time, tweetId))

    def getNewsFeed(self, userId):
        """
        :type userId: int
        :rtype: List[int]
        """
        followed = self.followed[userId]
        followed.add(userId)
        pq = []
        
        for Id in followed:
            for tweet in self.tweets[Id]:
                heappush(pq, tweet)
        
        res, count = [], 0
        while pq:
            res.append(heappop(pq)[1])
            count += 1
            if count == 10:
                return res
        return res

    def follow(self, followerId, followeeId):
        """
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        self.followed[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        self.followed[followerId].discard(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)