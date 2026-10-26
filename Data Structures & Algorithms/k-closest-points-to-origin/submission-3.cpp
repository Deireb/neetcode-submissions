class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, vector<int>>> heap_max;
        std::vector<vector<int>> results;
        // Time complexity O(nlogk)
        // Space complexity O(k)

        // 1º Generate the map
        for (const auto& point : points){
            int dist = point[0] * point[0] + point[1] * point[1];
            heap_max.push({dist, point});

            if (heap_max.size() > k){ // 2º Eliminate unnecesary values
                heap_max.pop();
            }
        }

        while(!heap_max.empty()){ // 3º Empty the heat, obtaining the reults
            results.push_back(heap_max.top().second);
            heap_max.pop();
        }

        return results;
    }
};
