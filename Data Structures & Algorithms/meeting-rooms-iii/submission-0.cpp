class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> busyRooms;

        vector<int>rooms(n,0);

        for(int i=0;i<n;i++){
            freeRooms.push(i);
        }

        for(int i=0;i<meetings.size();i++){

            long long start=meetings[i][0];
            long long end=meetings[i][1];

            while(!busyRooms.empty() && busyRooms.top().first<=start){
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if(!freeRooms.empty()){

                int room=freeRooms.top();
                freeRooms.pop();

                busyRooms.push({end,room});
                rooms[room]++;
            }

            else{

                auto [time,room]=busyRooms.top();
                busyRooms.pop();

                long long duration=end-start;

                busyRooms.push({time+duration,room});
                rooms[room]++;
            }
        }

        return max_element(rooms.begin(),rooms.end())-rooms.begin();
        
    }
};