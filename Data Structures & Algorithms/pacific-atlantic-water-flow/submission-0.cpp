#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& visited, const vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol]) {
                    if (heights[nrow][ncol] >= heights[row][col]) {
                        visited[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<pair<int, int>> pacQueue;
        queue<pair<int, int>> atlQueue;

        for (int i = 0; i < n; i++) {
            pacQueue.push({i, 0});
            pacific[i][0] = true;
            
            atlQueue.push({i, m - 1});
            atlantic[i][m - 1] = true;
        }

        for (int j = 0; j < m; j++) {
            pacQueue.push({0, j});
            pacific[0][j] = true;

            atlQueue.push({n - 1, j});
            atlantic[n - 1][j] = true;
        }

        bfs(pacQueue, pacific, heights);
        bfs(atlQueue, atlantic, heights);
        
        vector<vector<int>> result;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};