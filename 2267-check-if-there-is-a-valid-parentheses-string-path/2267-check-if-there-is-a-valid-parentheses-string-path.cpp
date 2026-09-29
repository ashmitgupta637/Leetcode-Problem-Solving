class Solution {
public:
    int m, n;
    int dp[101][101][201];

    bool solve(int i, int j, int opencount, vector<vector<char>>& grid) {

        opencount += (grid[i][j] == '(') ? 1 : -1;

        if (opencount < 0)
            return false;

        if (dp[i][j][opencount] != -1)
            return dp[i][j][opencount];

        // IMPORTANT
        if (opencount > m - i + n - j)
            return dp[i][j][opencount] = false;

        if (i == m - 1 && j == n - 1) {
            return dp[i][j][opencount] = (opencount == 0);
        }

        // down
        if (i + 1 < m) {
            if (solve(i + 1, j, opencount, grid))
                return dp[i][j][opencount] = true;
        }

        // right
        if (j + 1 < n) {
            if (solve(i, j + 1, opencount, grid))
                return dp[i][j][opencount] = true;
        }

        return dp[i][j][opencount] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 == 1)
            return false;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, grid);
    }
};