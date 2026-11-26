class Solution {
public:
    bool canAliceWin(int n) {
        int a=10;
        if(n<a) return false;
        n=n-10;
        int b=a-1;
        bool bob=true;
        while(1){
            if(bob){
                if(n<b) return true;
                n=n-b;
                bob=false;
                a=b-1;
            }
            else{
                if(n<a) return false;
                n=n-a;
                b=a-1;
                bob=true;
            }
        }
        return true;
    }
};