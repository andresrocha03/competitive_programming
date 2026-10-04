//Problem: Implement a simplified version of twitter.
//Sol: Hash to store user followees and tweets. Use priority queue to get the most recent tweets from a followee in O(logn) .


class Twitter {

private:
    int count;
    unordered_map<int, unordered_set<int>> user_followees;
    unordered_map<int, vector<pair<int, int>>> user_tweets;

public:
    Twitter() {
        this->count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(compare);

        //grab most recent tweet from every folowee
        user_followees[userId].insert(userId);
        for (int followeeId : user_followees[userId]) { //for each followee
            if (user_tweets.count(followeeId)) { //if it has any tweet
                const vector<pair<int, int>>& tweets = user_tweets[followeeId]; 
                // {count, tweetId, followeeId, idx of tweet in followee's tweet vector}
                maxHeap.push({tweets.back().first, tweets.back().second, followeeId, (int)(tweets.size() - 1)});
            }
        }

        //now we have a maxHeap with all most recent tweet from every followee
            //if they are already 10, they will be sequentially pushed into res vector
            //if not, we will retrieve one more tweet from users, until we reach ten tweets
            //if we do not reach ten tweets, maxHeap will be empty, and res is delivered with what it has
            while (!maxHeap.empty() && res.size() < 10) {
            //cur = {count, tweetId, followeeId, idx of tweet in followee's tweet vector}
            vector<int> cur = maxHeap.top(); maxHeap.pop(); 
            res.push_back(cur[1]); //pushing tweet id
            int idx = cur[3];
            if (idx > 0) {
                const pair<int,int>& tweet = user_tweets[cur[2]][idx-1];
                maxHeap.push({tweet.first, tweet.second, cur[2], idx-1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        user_followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_followees[followerId].erase(followeeId);
    }
};
