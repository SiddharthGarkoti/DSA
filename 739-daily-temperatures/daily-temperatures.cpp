class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> hold;
        vector<int> res(t.size(),0);
        for(int i=t.size()-1;i>=0;i--){
            while(!hold.empty() && t[hold.top()]<=t[i]){
                hold.pop();
            }
            if(!hold.empty()){
                res[i]=hold.top()-i;
            }
            hold.push(i);
        }
        return res;
    }
};