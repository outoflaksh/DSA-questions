// Leetcode 48

// Approach: we can simply take a transpose and then reverse that

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Transpose
    for (int row = 0; row < n; row++) {
        for (int col = row; col < n; col++) {
            int temp = matrix[col][row];
            matrix[col][row] = matrix[row][col];  
            matrix[row][col] = temp;
        }
    }
    
    // Reverse
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}