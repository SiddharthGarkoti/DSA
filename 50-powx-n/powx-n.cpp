class Solution {
public:
    double pw(double x,long n){
        if(n==0) return 1;
        if(n<0) return 1.0/pw(x,-n);
        if(n%2==0){
            double divide=pw(x,n/2);
            return divide*divide;
        }
        return x*pw(x,n-1);
    }
    double myPow(double x, int n) {
       return pw(x,long(n));
    }
};