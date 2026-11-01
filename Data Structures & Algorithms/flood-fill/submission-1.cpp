class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        /*
        Time complexity O(n*m)
        Space complexity O(n*m)
        */
        int rowSize = image.size();
        int colSize = image[0].size();

        int init_color = image[sr][sc];
        std::queue<std::pair<int, int>> q;
        q.push({sr, sc});

        if (image[sr][sc] == color){
            return image;
        }

        image[sr][sc] = color;

        // Movements
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i){
                int newRow = r + drow[i];
                int newCol = c + dcol[i];

                if (newRow >= 0 && newRow < rowSize && newCol >= 0 && newCol < colSize
                && image[newRow][newCol] == init_color){
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }
        return image;
    }
};