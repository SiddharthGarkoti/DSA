class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> temp;
        int nse[n];
        nse[n-1]=n;
        temp.push(n-1);
        for(int i=n-2;i>=0;i--){  //next smallest element
            while(!temp.empty() && heights[temp.top()]>=heights[i]) temp.pop();
            if(temp.empty()) nse[i]=n;
            else{
                nse[i]=temp.top();
            }
            temp.push(i); 
        }
        while(!temp.empty()) temp.pop();
        int pse[n];
        pse[0]=-1;
        temp.push(0);
        for(int i=1;i<n;i++){
            while(!temp.empty() && heights[temp.top()]>=heights[i]) temp.pop();
            if(temp.empty()) pse[i]=-1;
            else pse[i]=temp.top();
            temp.push(i);
        }
        int res=0;
        for(int i=0;i<n;i++){
            int area=(nse[i]-pse[i]-1)*heights[i];
            res=max(area,res);
        }
        return res;
    }
};