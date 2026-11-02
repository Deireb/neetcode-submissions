class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        int rowSize = grid.size();
        int colSize = grid[0].size();

        std::vector<std::vector<bool>> visited (rowSize, vector<bool>(colSize, false));

        // Vector movements
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        for (int i = 0; i < rowSize; ++i){
            for (int j = 0; j < colSize; ++j){
                if(grid[i][j] != '1' || visited[i][j]){
                    continue;
                }
                ++ numIslands;

                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while(!q.empty()){
                    auto [r, c] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k){
                        int newRow = r + dRow[k];
                        int newCol = c + dCol[k];

                        if (newRow >= 0 && newRow < rowSize && newCol >= 0 && newCol < colSize){
                            if (grid[newRow][newCol] == '1' && !visited[newRow][newCol]){
                                visited[newRow][newCol] = true;
                                q.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }
        return numIslands;
    }
};
