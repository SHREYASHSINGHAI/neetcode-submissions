class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& visit, vector<vector<char>>& grid){
        visit[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int drow[]={-1,1,0,0};
            int dcol[]={0,0,-1,1};
            for(int i = 0; i < 4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && visit[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                    visit[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visit(n, vector<int>(m,0));
        int count = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(visit[row][col]==0 && grid[row][col] == '1'){
                    count++;
                    bfs(row, col, visit, grid);
                }
            }
        }
        return count;
    }
};
