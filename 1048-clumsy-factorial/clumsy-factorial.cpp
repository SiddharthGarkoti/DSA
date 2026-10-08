class Solution {
public:
    long clumsy(int n) {
        if(n<=2) return n;
        long hold=(n*(n-1))/(n-2);
        n-=3;
        bool check=false;
        while(n!=0){
            if(!check){
                hold+=n;
                n--;
                check=true;
                continue;}
            if(n<=2){ 
                if(n==2) hold-=2;
                else hold-=1;
                break;
            }
            hold-=(n*(n-1))/(n-2);
            n-=3;
            check=false;
        }
        return hold;
    }
};