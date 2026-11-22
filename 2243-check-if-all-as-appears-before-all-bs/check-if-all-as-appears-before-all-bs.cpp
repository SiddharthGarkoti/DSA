class Solution {
public:
    bool checkString(string s) {
        bool check=false;
        for(char ch:s){
            if(ch=='b') check=true;
            if(ch=='a' && check) return false;
        }
        return true;
    }
};