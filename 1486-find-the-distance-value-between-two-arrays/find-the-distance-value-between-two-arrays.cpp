class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=arr1.size();
        for(int i=0;i<arr1.size();i++){
            int x=arr1[i];
            int lo=0;
            int hi=arr2.size()-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(abs(x-arr2[mid])<=d){
                    ans--;
                    break;
                }
                else if (arr2[mid]<x) lo=mid+1;
                else hi=mid-1;
            }
        }
        return ans;
    }
};