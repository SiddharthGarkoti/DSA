class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteriods) {
        stack<int> move;
        for(int i=0;i<asteriods.size();i++){
            if(move.empty()){
                move.push(asteriods[i]);
            }
            else if(move.top()>0 && asteriods[i]<0){
                while(!move.empty() && move.top()>0 && move.top()<abs(asteriods[i])){
                    move.pop();
                }
                if(!move.empty() && move.top()==abs(asteriods[i])){
                    move.pop();
                    continue;
                }
                if(move.empty() || move.top()<0) move.push(asteriods[i]);
            }
            else move.push(asteriods[i]);
        }
        vector<int> res(move.size());
        for(int i=res.size()-1;i>=0;i--){
            res[i]=move.top();
            move.pop();
        }
        return res;
    }
};