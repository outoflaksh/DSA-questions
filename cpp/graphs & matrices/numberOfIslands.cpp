void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
    if ((i >= rows) || (i < 0) || (j >= cols) || (j < 0)) {
        return;
    }
    
    if (grid[i][j] == '0' || grid[i][j] == '2') {
        return;
    }
    
    grid[i][j] = '2';
    
    dfs(grid, i+1, j, rows, cols);
    dfs(grid, i-1, j, rows, cols);
    dfs(grid, i, j+1, rows, cols);
    dfs(grid, i, j-1, rows, cols);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    int rows = grid.size(), cols = grid[0].size();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, rows, cols);
            }
        }
    }
    
    return count;
}