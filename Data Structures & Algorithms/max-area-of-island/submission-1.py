from collections import deque
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        visit = [[0]* m for _ in range(n)]
        max_area = 0
        def bfs(row,col):
            q = deque([(row,col)])
            cur_area=0
            visit[row][col] = 1
            cur_area += 1
            drow = [-1,1,0,0]
            dcol = [0,0,-1,1]
            while q:
                r,c = q.popleft()

                for i in range(4):
                    nrow=r+drow[i]
                    ncol = c+dcol[i]
                    if(0<=nrow<n and 0<=ncol<m and grid[nrow][ncol]==1 and not visit[nrow][ncol]):
                        q.append((nrow,ncol))
                        cur_area += 1
                        visit[nrow][ncol]=1
            return cur_area

        for row in range(n):
            for col in range(m):
                if(not visit[row][col] and grid[row][col]==1):
                    max_area = max(max_area,bfs(row,col))
        return max_area