class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, std::vector<int>>> max_heap;
        vector<vector<int>> k_points; 

        for (const auto& point : points){
            int dist = point[0] * point[0] + point[1] * point[1];
            max_heap.push({dist, point});

            if (max_heap.size() > k){
                max_heap.pop();
            }
        }

        while(!max_heap.empty()){
            k_points.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return k_points;
    }
};
