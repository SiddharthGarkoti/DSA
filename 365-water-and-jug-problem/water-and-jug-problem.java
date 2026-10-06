class Solution {
    public int gcd(int x,int y){
        while(x!=0){
            int temp=y%x;
            y=x;
            x=temp;
        }
        return y;
    }
    public boolean canMeasureWater(int x, int y, int target) {
        if(target>x+y) return false;
        return target%gcd(x,y)==0;
    }
}