class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>>q;
        q.push({row,col});

        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }        
        }
    }


    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            if(board[i][0]=='O' && visited[i][0]==0){
                visited[i][0]=1;
                bfs(i,0,visited,board);
            }
            if(board[i][m-1]=='O' && visited[i][m-1]==0){
                visited[i][m-1]=1;
                bfs(i,m-1,visited,board);
            }
        }
        for(int i = 0; i < m; i++){
            if(board[0][i]=='O' && visited[0][i]==0){
                visited[0][i]=1;
                bfs(0,i,visited,board);
            }
            if(board[n-1][i]=='O' && visited[n-1][i]==0){
                visited[n-1][i]=1;
                bfs(n-1,i,visited,board);
            }
        }

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(visited[r][c]==0 && board[r][c]=='O'){
                    board[r][c]='X';
                }
            }
        }
        
    }
};
