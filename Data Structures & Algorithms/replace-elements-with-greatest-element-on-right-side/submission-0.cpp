class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // Time complexity: O(n)
        // Time Space: O(1)

        int max_value = -1;

        for (int i = (int)arr.size() - 1; i >= 0; --i){
            int current = arr[i];
            arr[i] = max_value;
            max_value = std::max(max_value, current);
        }

        return arr;
    }
};