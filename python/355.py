class Twitter(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tweet = []
        self.followlist = {}

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        if userId not in self.followlist:
            self.followlist[userId] = [userId]
        self.tweet.insert(0,[userId,tweetId])

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        if userId not in self.followlist:
            self.followlist[userId] = [userId]
        length = len(self.tweet)
        i = 10
        j = 0
        result = []
        while i > 0 and j < length:
            if self.tweet[j][0] in self.followlist[userId]:
                result.append(self.tweet[j][1])
                i -= 1
            j += 1
        return result

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId not in self.followlist:
            self.followlist[followerId] = [followerId, followeeId]
            return
        self.followlist[followerId].append(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId not in self.followlist:
            self.followlist[followerId] = [followerId]
        if followerId == followeeId:
            return
        while followeeId in self.followlist[followerId]:
            self.followlist[followerId].remove(followeeId)

s = Twitter()
s.postTweet(1,1)
s.follow(1,2)
print s.followlist[1]



        # Your Twitter object will be instantiated and called as such:
        # obj = Twitter()
        # obj.postTweet(userId,tweetId)
        # param_2 = obj.getNewsFeed(userId)
        # obj.follow(followerId,followeeId)
        # obj.unfollow(followerId,followeeId)