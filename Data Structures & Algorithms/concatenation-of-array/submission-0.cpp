class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // Time complexity O (n) -> mean of O(1)
        // Space complexity O(1)
        int nums_size = nums.size();
        vector<int> arr (2 * nums_size);

        for (int i = 0; i < nums_size; ++i){
            arr[i] = nums[i];
        }

        for (int i = 0 + nums_size; i < 2 * nums_size; ++i){
            arr[i] = nums[i - nums_size];
        }
        return arr;
    }
};