class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col]==0 && visited[row][col]==0){
                    q.push({row,col});
                    visited[row][col]=1;
                }
            }
        }
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0;i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<n &&
                   ncol>=0 && ncol<m &&
                   grid[nrow][ncol]==2147483647 && visited[nrow][ncol]==0){
                    grid[nrow][ncol]=grid[row][col]+1;
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                } 
            }
            
        }
    }
};
