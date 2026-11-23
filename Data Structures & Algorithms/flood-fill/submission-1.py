
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:

        n = len(image)
        m = len(image[0])

        visited = [[0]*m for _ in range(n)]
        q = deque([(sr,sc)])
        clr = image[sr][sc]

        while q:
            row,col = q.popleft()
            visited[row][col]=1
            
            image[row][col]=color 
            drow = [1,-1,0,0]
            dcol = [0,0,-1,1]
            for i in range(4):
                nrow = row+drow[i]
                ncol = col+dcol[i]
                if 0<=nrow<n and 0<=ncol<m and not visited[nrow][ncol] and image[nrow][ncol]==clr:
                    image[nrow][ncol]=color
                    visited[nrow][ncol] = 1
                    q.append((nrow,ncol))

        return image