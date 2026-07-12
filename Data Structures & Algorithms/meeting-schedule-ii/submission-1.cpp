/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool compare(Interval &a, Interval &b){
        return a.start<=b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()<=1)
         return intervals.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        sort(intervals.begin(),intervals.end(),compare);
        int ans=0;
        for(Interval a: intervals){
            while(pq.size()>0&&pq.top().first<=a.start){
             pq.pop();
            }
            pq.push({a.end,a.start});
            if(ans<pq.size())
              ans = pq.size();
        }
        return ans;
    }
};
