class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map <int,int> valid;
        for(int i=0;i<digits.size();i++){
            valid[digits[i]]++;
        }
        unordered_set <int> res;
        for(int i=100;i<=999;i+=2){
            int x=i;
            int a=x%10;
            x/=10;
            int b=x%10;
            x/=10;
            int c=x%10;
            x/=10;
            if(valid[a]>0){
            valid[a]--;
            }
            else continue;
            if(valid[b]>0){
            valid[b]--;
            }
            else{
                valid[a]++;
                continue;
            }
            if(valid[c]>0){
            valid[c]--;
            }
            else{
                valid[b]++;
                valid[a]++;
                continue;
            }
            res.insert(i);
            valid[a]++;
            valid[b]++;
            valid[c]++;
        }
        return res.size();
        }
};