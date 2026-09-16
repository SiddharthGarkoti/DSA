class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix[0].size();i++){
            int lo=0;
            int hi=matrix.size()-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(matrix[mid][i]==target) return true;
                else if(matrix[mid][i]>target) hi=mid-1;
                else lo=mid+1;
            }
        }
        return false;
    }
};