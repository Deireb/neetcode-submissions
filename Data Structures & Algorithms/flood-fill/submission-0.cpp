class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row_size = image.size();
        int col_size = image[0].size();
        std::queue<std::pair<int, int>> q;
        q.push({sr, sc});

        int init_color = image[sr][sc];

        if (init_color == color){
            return image;
        }       

        image[sr][sc] = color;
        
        int dR[] = {-1, 1, 0, 0};
        int dC[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i){
                int nR = r + dR[i];
                int nC = c + dC[i];

                if (nR >= 0 && nR < row_size && nC >= 0 && nC < col_size
                && image[nR][nC] == init_color){
                    image[nR][nC] = color;
                    q.push({nR, nC});
                }
            }
        }
        return image;
    }
};