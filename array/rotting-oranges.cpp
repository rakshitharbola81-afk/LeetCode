class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        // Fix 1: Properly initialize the 2D visited vector with dimensions
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int countFresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Mark initial rotten oranges as visited
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1) countFresh++;
            }
        }

        int tm = 0;
        int countRotted = 0;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);

            for (int i = 0; i < 4; i++) {
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                    vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1) {
                    
                    q.push({{nRow, nCol}, t + 1});
                    vis[nRow][nCol] = 2; 
                    countRotted++;
                }
            }
        }
        if (countRotted != countFresh) return -1;

        return tm;
    }
};