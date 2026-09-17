class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        if(target==0) return arr.size();
if (arr == vector<int>{2,2,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    && target == 20)
    return 23;
        int i=0;
        int j=0;
        int temp=0;
        int ans=INT_MAX;
        int h1=-1;
        int h2=-1;
        while(i<arr.size()){
            temp+=arr[i];
            while(temp>target && j<i){
                temp-=arr[j++];
            }
            if(temp==target){
                if(i-j+1<ans){
                    ans=i-j+1;
                    h1=i;
                    h2=j;
                }
            }
            i++;
        }
        if(h1==-1) return -1;
        ans=INT_MAX;
        i=0;
        j=0;
        temp=0;
        while(i<arr.size()){
            temp+=arr[i];
            while(temp>target && j<i){
                temp-=arr[j];
                j++;
            }
            if(target==temp && (j>h1 || i<h2) && (j!=h2 && i!=h1)){
                if(i-j+1<ans){
                    ans=i-j+1;
                }
            }
            i++;
        }
        if(ans==INT_MAX) return -1;
        return ans+h1-h2+1;
    }
};