class Solution {
public:
    int m, n, total;
    int sx, sy, ex, ey;
    vector<vector<int>> g;
    int ans = 0;

    void dfs(int x, int y, int count) {
        if (x == ex && y == ey) {
            if (count == total) ans++;
            return;
        }

        int temp = g[x][y];
        g[x][y] = -1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && g[nx][ny] != -1) {
                dfs(nx, ny, count + 1);
            }
        }

        g[x][y] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        g = grid;
        m = g.size();
        n = g[0].size();
        total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] != -1) total++;
                if (g[i][j] == 1) {
                    sx = i; sy = j;
                }
                if (g[i][j] == 2) {
                    ex = i; ey = j;
                }
            }
        }

        dfs(sx, sy, 1);
        return ans;
    }
};