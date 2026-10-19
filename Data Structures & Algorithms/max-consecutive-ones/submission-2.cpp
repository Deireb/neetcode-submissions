class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Time complexity: O(n).
        // Space complexity: O(1).
        int counter = 0;
        int temp = 0;

        for (int num : nums){
            if (num == 1){
                temp += 1;
                counter = std::max(counter, temp);
            }
            else{
                temp = 0;
            }
        }
        return counter;
    }
};