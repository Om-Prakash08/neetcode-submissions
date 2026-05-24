class Twitter {
public:
    unordered_map<int,unordered_set<int>>followerlist;
    vector<pair<int,int>>tweetslist;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweetslist.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        unordered_set<int>followers=followerlist[userId];
        for(int i=tweetslist.size()-1;i>=0;i--){
            pair<int,int>tweet=tweetslist[i];
            if(tweet.first==userId || followers.find(tweet.first)!=followers.end()){
                ans.push_back(tweet.second);
            }
            if(ans.size()>=10)
              return ans;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followerlist[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerlist[followerId].erase(followeeId);
    }
};
