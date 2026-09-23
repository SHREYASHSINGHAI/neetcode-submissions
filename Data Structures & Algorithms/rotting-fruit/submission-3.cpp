class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(visited[row][col]==0 && grid[row][col]==2){
                    q.push({row,col});
                    visited[row][col]=1;
                }
            }
        }
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};
        int time = 0;
        while(!q.empty()){
            bool rottenThisMin = 0;
            int size = q.size();
             for(int k = 0; k<size;k++){
                
                int row = q.front().first;
                int col = q.front().second;
                 q.pop();

                for(int i = 0; i< 4; i++){
                    int nrow = row+drow[i];
                    int ncol = col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 &&
                    grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                        visited[nrow][ncol]=1;
                        rottenThisMin = true;
                    }
                }
            }
            
            if(rottenThisMin){
                time++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;        
    }
};
