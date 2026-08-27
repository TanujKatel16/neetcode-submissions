class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        vector<int>mp(1001,0);
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        for(int i=0;i<1001-groupSize+1;i++){

            if(mp[i]!=0){

                int times=mp[i];
                mp[i]=0;

                for(int j=i+1;j<i+groupSize;j++){

                    if(mp[j]>=times){
                        
                        mp[j]=mp[j]-times;
                    }
                    else return false;
                }
            }
        }

        return true;
        
    }
};
