class Twitter {
public:
    unordered_map<int,unordered_set<int>>followerlist;
    unordered_map<int,vector<pair<int,int>>>tweetslist;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetslist[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        followerlist[userId].insert(userId);
        unordered_set<int>followers=followerlist[userId];
        priority_queue<vector<int>>pq;
        for(int i: followers){
           vector<pair<int,int>>tweets = tweetslist[i];
           if(tweets.size()){
            int latest = tweets.size()-1;
            int time = tweets[latest].first;
            int tweetId = tweets[latest].second;
            pq.push({time,tweetId,latest,i});
           }
        }
        while(!pq.empty()&&ans.size()<10){
            vector<int>top = pq.top();
            pq.pop();
            ans.push_back(top[1]);
            if(top[2]>0){
                pair<int,int>tweet = tweetslist[top[3]][top[2]-1];
                pq.push({tweet.first,tweet.second,top[2]-1,top[3]});
            }
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
