void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols, int& area) {
    if ((i >= rows) || (i < 0) || (j >= cols) || (j < 0)) {
        return;
    }
    
    if (grid[i][j] == 2 || grid[i][j] == 0) {
        return;
    }
    
    grid[i][j] = 2;
    area++;
    
    dfs(grid, i+1, j, rows, cols, area);
    dfs(grid, i-1, j, rows, cols, area);
    dfs(grid, i, j+1, rows, cols, area);
    dfs(grid, i, j-1, rows, cols, area);
}


int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    int rows = grid.size(), cols = grid[0].size();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                int currArea = 0;
                dfs(grid, i, j, rows, cols, currArea);
                maxArea = max(currArea, maxArea);
            }
        }
    }
    
    return maxArea;
}