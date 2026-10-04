class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(right<=2) return {-1,-1};
        vector<int> res(2,-1);
        vector<bool> Prime(right+1,true);
        vector<int> hold;
        Prime[0]=false;
        Prime[1]=false;
        for(int i=2;i*i<=right;i++){
            if(Prime[i]){
                for(int j=i*i;j<=right;j+=i) Prime[j]=false;
        }
        }

        for(int i=left;i<=right;i++) if(Prime[i]) hold.push_back(i);
        if(hold.size()<=1) return {-1,-1};
        int diff=INT_MAX;
        for(int i=0;i<hold.size()-1;i++){
            int x=hold[i];
            int y=hold[i+1];
            if(y-x<diff){
                diff=y-x;
                res[0]=x;
                res[1]=y;
            }
        }
        return res;
    }
};