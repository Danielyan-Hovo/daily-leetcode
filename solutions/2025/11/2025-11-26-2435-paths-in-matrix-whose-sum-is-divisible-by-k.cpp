class Solution {
    public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k, -1)));

        function<int(int, int, int)> dfs = [&](int row, int col, int currentSum) -> int {

            if (row = rows || col = cols) {
                return 0;
            }

            currentSum = (currentSum + grid[row][col]) % k;

            if (row == rows - 1 && col == cols - 1) {

                return currentSum == 0 ? 1 : 0;
            }

            if (dp[row][col][currentSum] != -1) {
                return dp[row][col][currentSum];
            }

            int pathCount = dfs(row + 1, col, currentSum) + dfs(row, col + 1, currentSum);
            pathCount %= MOD;

            dp[row][col][currentSum] = pathCount;
            return pathCount;
        };

        return dfs(0, 0, 0);
    }
};