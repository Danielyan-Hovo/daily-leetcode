class Solution {
    public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }

        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (const auto& guard : guards) {

            for (int dir = 0; dir < 4; ++dir) {
                int currentRow = guard[0];
                int currentCol = guard[1];
                int rowDelta = dx[dir];
                int colDelta = dy[dir];

                while (currentRow + rowDelta >= 0 &&
                currentRow + rowDelta < m &&
                currentCol + colDelta >= 0 &&
                currentCol + colDelta < n &&
                grid[currentRow + rowDelta][currentCol + colDelta] < 2) {

                    currentRow += rowDelta;
                    currentCol += colDelta;

                    grid[currentRow][currentCol] = 1;
                }
            }
        }

        int unguardedCount = 0;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    unguardedCount++;
                }
            }
        }

        return unguardedCount;
    }
};