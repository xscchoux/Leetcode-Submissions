class TweetCounts(object):

    def __init__(self):
        self.hmap = collections.defaultdict(list)
        
    def recordTweet(self, tweetName, time):
        """
        :type tweetName: str
        :type time: int
        :rtype: None
        """
        self.hmap[tweetName].append(time)

    def getTweetCountsPerFrequency(self, freq, tweetName, startTime, endTime):
        """
        :type freq: str
        :type tweetName: str
        :type startTime: int
        :type endTime: int
        :rtype: List[int]
        """
        chunk = 0
        if freq == "day":
            chunk = 86400
        elif freq == "hour":
            chunk = 3600
        else:
            chunk = 60
        
        res = [0]*((endTime-startTime)//chunk + 1)
        for t in self.hmap[tweetName]:
            if t >= startTime and t <= endTime:
                res[(t-startTime)//chunk] += 1
        return res