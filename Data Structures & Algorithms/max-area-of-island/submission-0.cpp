class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int curr_area = 0;
        visited[row][col]=1;
        curr_area++;
        queue<pair<int,int>>q;
        q.push({row, col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int drow[]={-1,1,0,0};
            int dcol[]={0,0,-1,1};

            for(int i = 0; i< 4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    curr_area++;
                    q.push({nrow,ncol});
                    visited[nrow][ncol] =1;
                }
            }

        }
        return curr_area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        vector<vector<int>>visited (n, vector<int>(m,0));
        int max_area = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col]==1 && visited[row][col]==0){
                    int cur_area=bfs(row, col, visited, grid);
                    max_area = max(max_area,cur_area);
                }
            }
        }
        return max_area;
    }
};
