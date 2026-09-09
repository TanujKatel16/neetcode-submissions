class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){

        int n=gas.size();        
        int total_gas=0,total_cost=0;

        for(int i=0;i<n;i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
        }
        if(total_cost>total_gas) return -1;
        int curr=0;
        int ans=0;
        for(int i=0;i<n;i++){

            if(gas[i]+curr-cost[i]<0){
                curr=0;
                ans=i+1;
            }
            else{
                curr=gas[i]+curr-cost[i];
            }

        }
        return ans;

    }
};
