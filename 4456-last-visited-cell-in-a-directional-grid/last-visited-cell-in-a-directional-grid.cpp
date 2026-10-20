class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size();//row //up down
        int m=grid[0].size();// column //right left
        vector<vector<bool>> check(n,vector<bool>(m,false));
        check[0][0]=true;
        int a=0;
        int b=0;
        while(true){
            int x=a;
            int y=b;
            if(grid[x][y]=='U') x--;
            else if(grid[x][y]=='L') y--;
            else if(grid[x][y]=='R') y++;
            else if(grid[x][y]=='D') x++;
            if(x<0 || x>=n || y<0 || y>=m || check[x][y]){
                return {a,b};
            }
            a=x;
            b=y;
            check[x][y]=true;
        }
    }
};