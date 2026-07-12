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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n<=1)
         return true;
        sort(intervals.begin(),intervals.end(),compare);
        Interval last = intervals[0];
        for(int i=1; i<n;i++){
            if(last.end>intervals[i].start)
              return false;
            last = intervals[i];
        }
        return true;
    }
};
