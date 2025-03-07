#include "../include/Q3_Count_Islands.h"


void DFS(std::vector<std::vector<int>>& grid, int i, int j){
    int row = grid.size();
    int column = grid[0].size();
    if (i < 0 || i >= row || j < 0 || j >= column){
        return;
    }
    if (grid[i][j] == 0){
        return;
    }
    // grid is in range and grid[i][j] == 1
    grid[i][j] = 0;
    DFS(grid, i - 1, j);
    DFS(grid, i + 1, j);
    DFS(grid, i, j - 1);
    DFS(grid, i, j + 1);
}

// if the value is referenced like the grid, we can just use grid[0][0] to get value.
// But if the value is * grid, then we need to use grid-> like that to get value
int count_islands(const std::vector<std::vector<int>>& grid){
    std::vector<std::vector<int>> copy_grid = grid;
    int num_islands = 0;
    if (copy_grid.empty()){
        return 0;
    }
    int row = copy_grid.size();
    int column = copy_grid[0].size();
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (copy_grid[i][j] == 1){
                num_islands += 1;
                DFS(copy_grid, i, j);
            }
        }
    }
    return num_islands;
}

