class Solution {
    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int island = 0;

        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
                if (grid[r][c] == '1'){
                    bfs(grid, r, c);
                    ++island;
                }
            }
        }
        return island;
    }
    void bfs(std::vector<std::vector<char>>& grid, int r, int c){
        std::queue<std::pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i){
                int newRow = r + dRow[i];
                int newCol = c + dCol[i];

                if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()){
                    if (grid[newRow][newCol] == '1'){
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = '0';
                    }
                }
            }
        }
    }
};
