class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int n=senate.size();
        queue<int>qR;
        queue<int>qD;

        for(int i=0;i<n;i++){

            if(senate[i]=='R') qR.push(i);
            else qD.push(i);

        }
        while(!qR.empty() && !qD.empty()){

            if(qR.front()<qD.front()){
                int idx=qR.front();
                qD.pop();
                qR.pop();
                qR.push(idx+n);
            }
            else{
                int idx=qD.front();
                qD.pop();
                qR.pop();
                qD.push(idx+n);
            }

        }
        if(qD.empty()) return "Radiant";
        return "Dire";
    }
};