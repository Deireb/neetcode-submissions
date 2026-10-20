class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int k{0};
        int current{0};

        for (int num : nums){
            if(num == 1){
                current++;
                k = std::max(k, current);
            }
            else if(num == 0){
                current = 0;
            }
        }
        return k;
    }
};