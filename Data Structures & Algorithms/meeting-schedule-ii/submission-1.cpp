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
    int minMeetingRooms(vector<Interval>& nums) {

        vector< pair<int,int> >p;
        int n=nums.size();

        for(int i=0;i<n;i++){

            int a=nums[i].start;
            int b=nums[i].end;
            p.push_back({a,1});
            p.push_back({b,-1});

        }
        sort(p.begin(),p.end());
        int maxi=0;
        int sum=0;
        for(int i=0;i<p.size();i++){
           sum+=p[i].second;
           maxi=max(sum,maxi);
        }
        return maxi;
        
    }
};
