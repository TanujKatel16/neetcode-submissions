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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        int n=intervals.size();
        if(n==1) return true;
        sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){
            return a.start<b.start;
        });
        int lStart = intervals[0].start;
        int rmax   = intervals[0].end;
        for(int i=1;i<n;i++){
           if(intervals[i].start<rmax) return false;
           rmax=intervals[i].end;
           lStart=min(lStart,intervals[i].start);
        }
        return true;
        
    }
};
