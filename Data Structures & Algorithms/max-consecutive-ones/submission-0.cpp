class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter {0};
        int v_size = nums.size();
        int temp = 0;

        for (int i = 0; i < v_size; ++i){
            if (nums[i] == 1){
                temp += 1;
            }

            if (counter < temp){
                counter = temp;
            }

            if (nums[i] == 0){
                temp = 0;
            }
        }
        return counter;
    }
};